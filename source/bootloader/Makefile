
all:
	#Create bootloader
	gcc -I/home/hubert/os_source/lib/gnuefi_source/gnu-efi-3.0.15/inc -I/home/hubert/os_source/lib/gnuefi_source/gnu-efi-3.0.15/inc/x86_64 -fpic -ffreestanding -fno-stack-protector -fshort-wchar -mno-red-zone -DEFI_FUNCTION_WRAPPER -c bootloader.c -o /home/hubert/os_source/build/bootloader.o

	gcc -I/home/hubert/os_source/lib/gnuefi_source/gnu-efi-3.0.15/inc -I/home/hubert/os_source/lib/gnuefi_source/gnu-efi-3.0.15/inc/x86_64 -fpic -ffreestanding -fno-stack-protector -fshort-wchar -mno-red-zone -DEFI_FUNCTION_WRAPPER -mabi=ms -c vga.s -o /home/hubert/os_source/build/vga.o

	ld -shared -Bsymbolic -nostdlib -L/home/hubert/os_source/lib/compiled_gnuefi -L/home/hubert/os_source/lib/manual_compiled_files_gnuefi -T/home/hubert/os_source/lib/gnuefi_source/gnu-efi-3.0.15/gnuefi/elf_x86_64_efi.lds /home/hubert/os_source/lib/gnuefi_source/gnu-efi-3.0.15/gnuefi/crt0-efi-x86_64.o /home/hubert/os_source/build/bootloader.o /home/hubert/os_source/build/vga.o -o /home/hubert/os_source/build/bootloader.so /home/hubert/os_source/lib/manual_compiled_files_gnuefi/libgnuefi.a /home/hubert/os_source/lib/compiled_gnuefi/libefi.a
	objcopy -j .text -j .sdata -j .data -j .rodata -j .rel -j .rela -j .reloc -j .dynamic -j .dynsym --target efi-app-x86_64 /home/hubert/os_source/build/bootloader.so /home/hubert/os_source/build/bootloader.efi
	#Create img
	rm -f /home/hubert/os_source/build/efiboot.img
	truncate -s 512M /home/hubert/os_source/build/efiboot.img
	sudo mkfs.fat -F32 /home/hubert/os_source/build/efiboot.img
	sudo mmd -i /home/hubert/os_source/build/efiboot.img ::EFI
	sudo mmd -i /home/hubert/os_source/build/efiboot.img ::EFI/BOOT
	cp /home/hubert/os_source/build/bootloader.efi /home/hubert/os_source/build/bootloader1.efi
	mv /home/hubert/os_source/build/bootloader.efi /home/hubert/os_source/build/BOOTX64.EFI
	mcopy -i /home/hubert/os_source/build/efiboot.img /home/hubert/os_source/build/BOOTX64.EFI ::EFI/BOOT/
	mcopy -i /home/hubert/os_source/build/efiboot.img /home/hubert/os_source/build/kernel.elf ::EFI/BOOT/kernel.elf

	rm -f /home/hubert/os_source/qemu_test/efiboot.img
	cp /home/hubert/os_source/build/efiboot.img /home/hubert/os_source/qemu_test/efiboot.img

	rm /home/hubert/os_source/build/BOOTX64.EFI
	rm /home/hubert/os_source/build/bootloader.o
	rm /home/hubert/os_source/build/vga.o
	rm /home/hubert/os_source/build/bootloader.so
