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

//EFI STATUS declarated for ms abi
EFI_STATUS EFIAPI
efi_main (EFI_HANDLE Image_handle, EFI_SYSTEM_TABLE *System_table)
{
    //InitializeLib
    InitializeLib(Image_handle, System_table);

    //Define variables
    EFI_STATUS Status;
    EFI_LOADED_IMAGE_PROTOCOL * Loaded_image = NULL;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL * File_system = NULL;
    EFI_FILE_PROTOCOL * Root = NULL;
    EFI_FILE_PROTOCOL * Kernel_file = NULL;

    //GOP variables getter

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

    //Changing screen resolution

    for (UINT32 i = 0; i < gop->Mode->MaxMode; i++) {
        EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
        UINTN size;

        Status = uefi_call_wrapper(
            gop->QueryMode,
            4,
            gop,
            i,
            &size,
            &info
        );

        if (EFI_ERROR(Status)) {
            Print(L"Bootloader error: %r\n",Status);
            return Status;
        }

        if (info->HorizontalResolution == 1920 &&
            info->VerticalResolution == 1080) {

        Status = uefi_call_wrapper(
            gop->SetMode,
            2,
            gop,
            i
        );
            break;
            }

    }


    //Declarate Framebuffer structure
    Framebuffer *fb;

    //Alocating memory for Framebuffer structure
    Status = uefi_call_wrapper(BS->AllocatePool, 3, EfiLoaderData, sizeof(Framebuffer), (VOID**)&fb);

    if (EFI_ERROR(Status)) {
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //Get parametrs from EFI structure to Framebuffer structure
    fb->address = gop->Mode->FrameBufferBase;
    fb->width  = gop->Mode->Info->HorizontalResolution;
    fb->height = gop->Mode->Info->VerticalResolution;
    fb->pitch  = gop->Mode->Info->PixelsPerScanLine;
    fb->bits_per_pixel = 32;


    //Print logo

    UINTN col, row;

    //Getting actual position of coursor
    Status = uefi_call_wrapper(System_table->ConOut->QueryMode,4,System_table->ConOut,System_table->ConOut->Mode->Mode,&col,&row);
    Print(L"#             #   ####   #       #  #########   #          #########     ####       ####   #########");
    //Going to new line by row += 1
    row += 1;
    //Set new coursor position
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L" #           #   #    #   #     #   #           #          #        #   #    #     #    #      #    ");
    row += 1;
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L"  #         #   #      #   #   #    #           #          #        #  #      #   #      #     #    ");
    row += 1;
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L"   #       #    #      #    # #     #########   #          #########   #      #   #      #     #    ");
    row += 1;
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L"    #     #     #      #     #      #           #          #        #  #      #   #      #     #    ");
    row += 1;
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L"     #   #      #      #    # #     #           #          #        #  #      #   #      #     #    ");
    row += 1;
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L"      # #        #    #    #   #    #           #          #        #   #    #     #    #      #    ");
    row += 1;
    Status = uefi_call_wrapper(System_table->ConOut->SetCursorPosition,3,System_table->ConOut,0,row);
    Print(L"       #          ####    #     #   #########   #########  #########     ####       ####       #    ");

    //sleep

    for(long i = 0; i <999999995; i++){

    }


    //Download protocol LoadedImage
    //For loading Kernel file
    Status = uefi_call_wrapper(
            System_table->BootServices->OpenProtocol,
            6,
            Image_handle,
            &gEfiLoadedImageProtocolGuid,
            (void**) & Loaded_image,
            Image_handle,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);

    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //Download protocol SimpleFileSystem
    //For acces to file system in image
    Status = uefi_call_wrapper(
            System_table->BootServices->OpenProtocol,
            6,
            Loaded_image->DeviceHandle,
            &gEfiSimpleFileSystemProtocolGuid,
            (void**) & File_system,
            NULL,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL);

    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //Open Root directory
    Status = uefi_call_wrapper(File_system->OpenVolume,
            2,
            File_system,
            &Root);

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

    if(EFI_ERROR(Status)){
        Print(L"Bootloader error: %r\n",Status);
        return Status;
    }

    //Loading kernel to RAM

    //Allocate bufor in RAM for ELF header
    //Elf header is important because
    //it have the important data of how much
    //we need RAM memory for kernel.
    //So thanks for that we know exaclty how much
    //address needs kernel in RAM.
    Elf64_Ehdr *Elf_header;

    Status = uefi_call_wrapper(
            System_table->BootServices->AllocatePool,
            3,
            EfiLoaderData,
            sizeof(Elf64_Ehdr),
            (void**)&Elf_header);
            //(void**)&Elf_header;
            //it is to definie variable Elf_header to get correct elf data
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
    //
    //We can now validate tha elf header that we know the kernel.elf is valid file format
    //
    //We need to check it to be sure that we dont have
    //a crash later from that

    //  >> Check <<
    if(Elf_header->e_ident[0] != 0x7F ||
        Elf_header->e_ident[1] != 'E' ||
        Elf_header->e_ident[2] != 'L' ||
        Elf_header->e_ident[3] != 'F'
        ){
        Print(L"Kernel header are invalid, the kernel file might be broken or invalid.\n");
        return EFI_LOAD_ERROR;
    }

    //Now if we are there it sounds that header and probably kernel.elf file are vaild.
    //So we can now go back to allocate memory for kernel and load it to this sectors

    //The header are valid.
    //We can now allocate memory for kernel and load in to allocated sectors
    //But before that we need to allocate memory for Program_headers

    //Allocating memory for kernel Program_headers

    Elf64_Phdr * Program_headers;

    UINTN Program_headers_size = Elf_header->e_phnum *
        sizeof(Elf64_Phdr);
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
    //for allocating memory for Program_headers,
    //not confuse with allocating kernel.elf.
    //We just alloacted only memory from kernel headers and elf_headers.

    //We will set position for kernel.elf, the elf parameters
    Status = uefi_call_wrapper(
            Kernel_file->SetPosition,
            2,
            Kernel_file,
            Elf_header->e_phoff);

    if(EFI_ERROR(Status)){
            Print(L"Bootloader error: %r\n",Status);
            return Status;
    }

    UINTN size = Program_headers_size;

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

    //Now we can move to estimates how much sectors in RAM

    EFI_PHYSICAL_ADDRESS kernel_start = UINT64_MAX;
    EFI_PHYSICAL_ADDRESS kernel_end = 0;

    //kernel start is the start address in RAM
    //of future kernel that will be start there.
    //
    //kernel_end is the end address in RAM
    //of future kernel that will be end there.

    //Now we will be selecting right absolut address in RAM for our kernel.
    //To do this we need to be sure that feture sector will be free from
    //for example uefi/efi data variables that already is allocated in ram,
    //We don't wanna overwrite it
    //So we will chose the clear sector of RAM and it also needs to be
    //right size of this sector



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

    //We calculate how much memory kernel needs/weight.
    UINTN Kernel_size = kernel_end - kernel_start;

    //We calcualte how much pages kernel needs.
    UINTN pages = (Kernel_size + EFI_PAGE_SIZE - 1) / EFI_PAGE_SIZE;

    //Now we can allocate the memory for kernel.
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

    //We have allocated memory for kernel.
    //Now we will be injecting kernel to this sectors.

    INT64 slide = KernelAddr - kernel_start;

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


    //We have been injected kernel.elf to RAM.

    //We can do stub after efi aplication will end and there will
    //be jump to kernel

    //Stub is to translate ms abi (efi aplication in default works in ms abi)
    //to kernel abi (kernel don't needs to have ms abi)
    //For example translate ms abi --> SystemV abi

    //But after that we need give kernel memory map.
    //Memory map have a address where efi and uefi variables
    //are stored, kernel don't want to ovewrite this variable.


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
    //We need to alocate it to RAM and inject it.
    //And the kernel will access it from RAM

    //Alloacting memory map

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

    //Calculation how many pages kernel needs

    UINTN pages2 = (kernel_end - kernel_start + 0xFFF)/0x1000;

    //Reserve memory for kernel

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

    //Calculate the relocation (slide)
    //kernel was linked in kernel_start
    //But loaded under KernelAddr
    //Now we need to move all addresses
    //about slide2

    INT64 slide2 = KernelAddr - kernel_start;

    //Loading segments ELF
    //Iterating on headers program ELF
    //We chose the segments of PT_LOAD

    for(UINTN i=0;i<Elf_header->e_phnum;i++){
        if(Program_headers[i].p_type != PT_LOAD) continue;

        //Designation address destination in RAM

        void *dest = (void*)(Program_headers[i].p_vaddr + slide2);
        UINTN size = Program_headers[i].p_filesz;

        //Set the position of file
        //We are moving to sector in file
        //Where segment starts.

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

        //Loading data segment
        //Copying segment from file to RAM

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

        //Zeroing section of BSS
        //If segment have bigger size in RAM then in file
        //Missing part = .bss
        //It needs to be zeroing

        UINTN bss = Program_headers[i].p_memsz - Program_headers[i].p_filesz;
        if(bss>0){
            SetMem((UINT8*)dest + Program_headers[i].p_filesz, bss, 0);
        }

    }

    //Second downloading memory map
    //It must be done for proper kernel jump
    //Because AllocatePages changes memory map
    //old memory map is invalid now
    //ExitBootServices requires exactly actual
    //memory map

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

    //Exiting BootServices

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

    //This is jump to kernel if the kernel have the same ABI
    //EFI app = MS abi
    //to compile kernel with ms abi, while compilation you need to add flag
    //"-mabi=ms"

    //With kernel jump we give to it indicator of GOP initialized structure
    //that structure is definied
    //In form of register parameters
    //thats why _start(fb << parameter);
    VOID (*_start)(Framebuffer*) = (VOID(*)(Framebuffer*))(KernelAddr + Elf_header->e_entry - kernel_start);
    _start(fb);

}
