#include "/home/hubert/project_kernel/gnu-efi/gnu-efi-3.0.15/inc/efi.h"
#include "/home/hubert/project_kernel/gnu-efi/gnu-efi-3.0.15/inc/efilib.h"
#include <elf.h>

//GOP structure definie
typedef struct {
    uint64_t address;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bits_per_pixel;
} Framebuffer;
//GOP structure definie

EFI_STATUS EFIAPI
efi_main (EFI_HANDLE Image_handle, EFI_SYSTEM_TABLE *System_table)
{
    //InitializeLib
    InitializeLib(Image_handle, System_table);

    //Test correct compilation
    Print(L"image=%lx st=%lx\n", Image_handle, System_table);
    //Define variables

    EFI_STATUS Status;
    EFI_LOADED_IMAGE_PROTOCOL * Loaded_image = NULL;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL * File_system = NULL;
    EFI_FILE_PROTOCOL * Root = NULL;
    EFI_FILE_PROTOCOL * Kernel_file = NULL;

    //Download protocol LoadedImage

    Status = uefi_call_wrapper(
            System_table->BootServices->OpenProtocol,
            6,
            Image_handle,
            &gEfiLoadedImageProtocolGuid,
            (void**) & Loaded_image,
            Image_handle,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);

    //Get status, handle exception
    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }
    //Download protocol SimpleFileSystem

    Status = uefi_call_wrapper(
            System_table->BootServices->OpenProtocol,
            6,
            Loaded_image->DeviceHandle,
            &gEfiSimpleFileSystemProtocolGuid,
            (void**) & File_system,
            NULL,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);

    //Get status, handle exception
    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }
    //Open Root directory

    Status = uefi_call_wrapper(File_system->OpenVolume,
            2,
            File_system,
            &Root);

    //Get status, handle exception
    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //Open kernel.elf
    Status = uefi_call_wrapper(
            Root->Open,
            5,
            Root,
            &Kernel_file,
            L"EFI\\BOOT\\kernel.elf",
            EFI_FILE_MODE_READ,
            0);

    //Get status, handle exception
    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }
    //Checkpoint//
    //////////////

    //Loading kernel to RAM

    //Allocate bufor in RAM for ELF header
    //Elf header is important because
    //it have the important data of how much
    //we need memory for kernel.
    //So thenks for that we know exaclty how much
    //address need kernel in RAM.
    Elf64_Ehdr *Elf_header;

    Status = uefi_call_wrapper(
            System_table->BootServices->AllocatePool,
            3,
            EfiLoaderData,
            sizeof(Elf64_Ehdr),
            (void**)&Elf_header);
            //(void**)&Elf_header;
            //is to definie variable Elf_header the correct elf data
            //from kernel.elf file.
    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }
    //So we have the information about size of
    //kernel.elf in Elf_header variable
    //We can now start reading it
    //to analize how much we need to allocate.


    UINTN size_of_kernel = sizeof(Elf64_Ehdr);

    Status = uefi_call_wrapper(
            Kernel_file->Read,
            3,
            Kernel_file,
            &size_of_kernel,
            Elf_header);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }
    //So if we load or header from Elf_header variable
    //to size_of_kernel variable (it must be done)
    //
    //We can now validate that elf header that first
    //of all give us kernel.elf file is valid.
    //
    //We need to check it to be sure that we dont have
    //a crash later from that, so we do a exception.

    //  >> Exception <<
    if(Elf_header->e_ident[0] != 0x7F ||
        Elf_header->e_ident[1] != 'E' ||
        Elf_header->e_ident[2] != 'L' ||
        Elf_header->e_ident[3] != 'F'
        ){
        Print(L"Kernel header are invalid, the kernel file might be broken or invalid.\n");
        Print(L"Error massege from uefi get status: %r\n", EFI_LOAD_ERROR);
        return EFI_LOAD_ERROR;
    }
    //Now if we are there it sounds that header and probably kernel.elf file are vaild.
    //So we can now go back to allocate memory for kernel and load it to this sectors

    //Allocating memory for kernel headers in our memory

    Elf64_Phdr * Program_headers;

    UINTN Program_headers_size = Elf_header->e_phnum *
        sizeof(Elf64_Phdr);
    //Program_headers_size this is demand.
    //of the real value of size of headers program.
    Status = uefi_call_wrapper(
            System_table->BootServices->AllocatePool,
            3,
            EfiLoaderData,
            Program_headers_size,
            (void**)&Program_headers);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }
    //Yup, thats block code above is responsible
    //for Allocating memory for Program headers,
    //not confuse with allocating kernel.elf.
    //We just alloacted only memory from kernel headers.

    //Now we jump to our file
    //Basically we need to SetPosition with Kernel_file variable
    Status = uefi_call_wrapper(
            Kernel_file->SetPosition,
            2,
            Kernel_file,
            Elf_header->e_phoff);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }

    //So we just did a jump basically to vaild memory of
    //our hard drive to kernel file thanks to Elf_headers.

    //Now if we are in right place we do a reading of kernel
    UINTN size = Program_headers_size;
    //Real size of program headers from demand before.

    Status = uefi_call_wrapper(
            Kernel_file->Read,
            3,
            Kernel_file,
            &size,
            Program_headers);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }

    //We just readed kernel.elf file from hard drive disk
    //valid sector.
    //Now we can move to estimates how much sectors in RAM
    //we need to inject kernel into this.

    EFI_PHYSICAL_ADDRESS kernel_start = UINT64_MAX;
    //UINT64_MAX why we definied like this ?
    EFI_PHYSICAL_ADDRESS kernel_end = 0;

    //kernel start is the start address in RAM
    //of future kernel that will be start there.
    //
    //kernel_end is the end address in RAM
    //of future kernel that will be end there.

    //So now we can estimate how values will have
    //kernel_start and kernel_end



    for(UINTN i = 0; i < Elf_header->e_phnum; i++){

        if(Program_headers[i].p_type != PT_LOAD){
            continue;
        }

        if(Program_headers[i].p_vaddr < kernel_start){
            kernel_start = Program_headers[i].p_paddr;
        }

        if(Program_headers[i].p_vaddr + Program_headers[i]
                .p_memsz > kernel_end){
            kernel_end = Program_headers[i].p_vaddr +
                Program_headers[i].p_memsz;
        }

    }


    //So now we know how much kernel weights in RAM.
    //We can allocate that memory in.
    //We give the job of select start address to the
    //uefi, we only definie how much not from what start.

    UINTN Kernel_size = kernel_end - kernel_start;
    //We calculate how much memory kernel needs/weight.

    UINTN pages = (Kernel_size + EFI_PAGE_SIZE - 1) / EFI_PAGE_SIZE;
    //We calcualte how much pages kernel needs.

    //Now we can allocate the memory.
    EFI_PHYSICAL_ADDRESS KernelAddr = 0;
    Status = uefi_call_wrapper(
            System_table->BootServices->AllocatePages,
            4,
            AllocateAnyPages, // AlocatePages
            EfiLoaderData,
            pages,
            &KernelAddr);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }
    INT64 slide = KernelAddr - kernel_start;
    //Now when we have allocated/reserved memory in RAM.
    //We can now inject kernel.elf to this sectors.
    for(UINTN i = 0; i < Elf_header->e_phnum; i++){

        if(Program_headers[i].p_type != PT_LOAD){
            continue;
        }
        void *dest = (void*)(Program_headers[i].p_vaddr + slide);
        UINTN size = Program_headers[i].p_filesz;

        Status = uefi_call_wrapper(
                Kernel_file->SetPosition,
                2,
                Kernel_file,
                Program_headers[i].p_offset);

        if(EFI_ERROR(Status)){
                Print(L"Bootloader error: %r\n",Status);
                return Status;
        }
        //UINTN size = Program_headers[i].p_filesz;
        Status = uefi_call_wrapper(
                Kernel_file->Read,
                3,
                Kernel_file,
                &size,
                dest);//(void*)(Program_headers[i].p_paddr));

        if(EFI_ERROR(Status)){
                Print(L"Bootloader error: %r\n",Status);
                return Status;
        }

    UINTN bss = Program_headers[i].p_memsz - Program_headers[i].p_filesz;
    if(bss > 0){
        SetMem(
            (VOID *)((UINT8 *)dest + Program_headers[i].p_filesz),
            bss,
            0);

    }
    }

    //Now kernel is injected to RAM.
    //Checkpoint 2//
    ////////////////

    //Kernel is loaded into the valid addreses of RAM.
    //The last things we need done is to:
    //supply kernel with memory map.
    //Kernel needs to know where in ram is firmware,
    //UEFI,to don't overwrite it.
    //
    //And we need after that jump to kernel with stumb.
    //
    //Stumb is basically translate Microsoft ABI x86
    //That every UEFI apliaction need to have this is
    //essential. Because this is efi standard.
    //But kernel can have other stantdard like
    //System-V.
    //So before jump we will need to translate the ABI.
    //From MS x86 -> SYS-V

    //So after that speech.
    //We will download Memory Map.

    UINTN mmap_size = 0;
    EFI_MEMORY_DESCRIPTOR * mmap = NULL;
    UINTN map_key;
    UINTN desc_size;
    UINT32 desc_version;
    Status = uefi_call_wrapper(
            System_table->BootServices->
            GetMemoryMap,
            5,
            &mmap_size,
            NULL,
            &map_key,
            &desc_size,
            &desc_version);

    if (EFI_ERROR(Status)) {
        Print(L"Bootloader error: %r\n",Status);
        //return Status;
    }
    mmap_size += 2 * desc_size;
    //Now when we just downloaded the memory map
    //We need to alocate it to RAM beacuse kernel need
    //to get it somehow
    //Remeber that EFI apliaction like this cannot
    //comunicate easy with kernel.
    //This is blocked by architecture or UEFI.
    //
    //In other words we need to leave a letter
    //at the door to kernel.
    //This door are RAM.
    //
    //And kernel task is to pick up this information.
    //And use it.


    //So we will alloacte and inject to memory
    //this information (map)
    //Alloaction

    Status = uefi_call_wrapper(
            System_table->BootServices->
            AllocatePool,
            3,
            EfiLoaderData,
            mmap_size,
            //&map_key,
            (void**)&mmap);

    //if (Status != EFI_BUFFER_TOO_SMALL) {
        //Print(L"Unexpected GetMemoryMap status: %r\n", Status);
        //return Status;
    //}
    if (EFI_ERROR(Status)) {
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //Inject memory map to alloacted sectors.

    UINTN actual_size = mmap_size;
    Status = uefi_call_wrapper(
            System_table->BootServices->
            GetMemoryMap,
            5,
            &actual_size,
            mmap,
            &map_key,
            &desc_size,
            &desc_version);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }
    //So after all this strugles and tasks
    //our EFI tired apliaction we close and
    //we are jumping to kernel.

    UINTN pages2 = (kernel_end - kernel_start + 0xFFF)/0x1000;

    Status = uefi_call_wrapper(System_table->BootServices->
            AllocatePages,
            4,
            AllocateAnyPages,
            EfiLoaderData,
            pages2,
            &KernelAddr);
    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }

    INT64 slide2 = KernelAddr - kernel_start;

    for(UINTN i=0;i<Elf_header->e_phnum;i++){
        if(Program_headers[i].p_type != PT_LOAD) continue;

        void *dest = (void*)(Program_headers[i].p_vaddr + slide2);
        UINTN size = Program_headers[i].p_filesz;

        Status = uefi_call_wrapper(
            Kernel_file->SetPosition,
            2,
            Kernel_file,
            Program_headers[i].p_offset
        );
        if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
        }

        Status = uefi_call_wrapper(
            Kernel_file->Read,
            3,
            Kernel_file,
            &size,
            dest
        );
        if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
        }


        UINTN bss = Program_headers[i].p_memsz - Program_headers[i].p_filesz;
        if(bss>0){
            SetMem((UINT8*)dest + Program_headers[i].p_filesz, bss, 0);
        }

    }
    UINTN actual_size2 = mmap_size;
    Status = uefi_call_wrapper(
        System_table->BootServices->
        GetMemoryMap,
        5,
        &actual_size2,
        mmap,
        &map_key,
        &desc_size,
        &desc_version);
    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //GOP variable downloading

    EFI_GRAPHICS_OUTPUT_PROTOCOL *gop;
    EFI_GUID gop_guid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;

    Status = uefi_call_wrapper(
        BS->LocateProtocol,
        3,
        &gop_guid,
        NULL,
        (void**)&gop
    );

    if (EFI_ERROR(Status)) {
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    Framebuffer *fb;

    Status = uefi_call_wrapper(BS->AllocatePool, 3, EfiLoaderData, sizeof(Framebuffer), (VOID**)&fb);

    if (EFI_ERROR(Status)) {
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    fb->address = gop->Mode->FrameBufferBase;
    fb->width  = gop->Mode->Info->HorizontalResolution;
    fb->height = gop->Mode->Info->VerticalResolution;
    fb->pitch  = gop->Mode->Info->PixelsPerScanLine;
    fb->bits_per_pixel = 32;

    //GOP variable downloading

    Status = uefi_call_wrapper(System_table->BootServices
        ->ExitBootServices,
        2,
        Image_handle,
        map_key
    );
    if (EFI_ERROR(Status)) {
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //This is jump if the kernel have the same ABI
    //like EFI so MSx86
    //to compile kernel for this you need to add flag
    //while compilation
    //"-mabi=ms"
    //typedef void (*kernel_entry_t)(void);

    //kernel_entry_t KernelEntry =
        //(kernel_entry_t)Elf_header->e_entry;
    //KernelEntry();
    //jump to kernel ms abi
    VOID (*_start)(Framebuffer*) = (VOID(*)(Framebuffer*))(KernelAddr + Elf_header->e_entry - kernel_start);
    _start(fb);

}
