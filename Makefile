all:
	#kernel
	rm -f ./build/kernel.elf
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c ./source/kernel/entry.s -o ./build/entry.o
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c ./source/kernel/kernel.c -o ./build/kernel.o
	ld -nostdlib -T ./linkers/link.ld -o ./build/kernel.elf ./build/entry.o ./build/kernel.o

	rm ./build/entry.o
	rm ./build/kernel.o

	#bootloader
	gcc -I./lib/gnuefi_source/gnu-efi-3.0.15/inc -I./lib/gnuefi_source/gnu-efi-3.0.15/inc/x86_64 -fpic -ffreestanding -fno-stack-protector -fshort-wchar -mno-red-zone -DEFI_FUNCTION_WRAPPER -c ./source/bootloader/bootloader.c -o ./build/bootloader.o

	ld -shared -Bsymbolic -nostdlib -L./lib/compiled_gnuefi -L./lib/manual_compiled_files_gnuefi -T./lib/gnuefi_source/gnu-efi-3.0.15/gnuefi/elf_x86_64_efi.lds ./lib/gnuefi_source/gnu-efi-3.0.15/gnuefi/crt0-efi-x86_64.o ./build/bootloader.o -o ./build/bootloader.so ./lib/manual_compiled_files_gnuefi/libgnuefi.a ./lib/compiled_gnuefi/libefi.a
	objcopy -j .text -j .sdata -j .data -j .rodata -j .rel -j .rela -j .reloc -j .dynamic -j .dynsym --target efi-app-x86_64 ./build/bootloader.so ./build/bootloader.efi

	#Create img
	rm -f ./build/efiboot.img
	truncate -s 512M ./build/efiboot.img
	sudo mkfs.fat -F32 ./build/efiboot.img
	sudo mmd -i ./build/efiboot.img ::EFI
	sudo mmd -i ./build/efiboot.img ::EFI/BOOT
	mv ./build/bootloader.efi ./build/BOOTX64.EFI
	mcopy -i ./build/efiboot.img ./build/BOOTX64.EFI ::EFI/BOOT/
	mcopy -i ./build/efiboot.img ./build/kernel.elf ::EFI/BOOT/

	rm -f ./qemu_test/efiboot.img
	cp ./build/efiboot.img ./qemu_test/efiboot.img

	rm ./build/BOOTX64.EFI
	rm ./build/bootloader.o
	rm ./build/bootloader.so
	rm ./build/kernel.elf
