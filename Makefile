all:
	#kernel
	rm -f ./build/kernel.elf
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c ./source/kernel/entry.s -o ./build/entry.o
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c ./source/kernel/kernel.c -o ./build/kernel.o
	ld -nostdlib -T ./linkers/link.ld -o ./build/kernel.elf ./build/entry.o ./build/kernel.o

	rm ./build/entry.o
	rm ./build/kernel.o

	#bootloader
	gcc -I./usr/include/efi -I/usr/include/efi/x86_64 -fpic -ffreestanding -fno-stack-protector -fshort-wchar -mno-red-zone -DEFI_FUNCTION_WRAPPER -c ./source/bootloader/bootloader.c -o ./build/bootloader.o

	ld -shared -Bsymbolic -nostdlib -T/usr/lib/elf_x86_64_efi.lds /usr/lib/crt0-efi-x86_64.o ./build/bootloader.o -o ./build/bootloader.so /usr/lib/libgnuefi.a /usr/lib/libefi.a
	objcopy -j .text -j .sdata -j .data -j .rodata -j .rel -j .rela -j .reloc -j .dynamic -j .dynsym --target efi-app-x86_64 ./build/bootloader.so ./build/bootloader.efi

	#Create img
	rm -f ./build/MagmaCubeOS.img
	truncate -s 512M ./build/MagmaCubeOS.img
	/usr/sbin/mkfs.fat -F32 ./build/MagmaCubeOS.img
	/usr/bin/mmd -i ./build/MagmaCubeOS.img ::EFI
	/usr/bin/mmd -i ./build/MagmaCubeOS.img ::EFI/BOOT
	mv ./build/bootloader.efi ./build/BOOTX64.EFI
	mcopy -i ./build/MagmaCubeOS.img ./build/BOOTX64.EFI ::EFI/BOOT/
	mcopy -i ./build/MagmaCubeOS.img ./build/kernel.elf ::EFI/BOOT/

	rm -f ./qemu_test/MagmaCubeOS.img
	cp ./build/MagmaCubeOS.img ./qemu_test/MagmaCubeOS.img

	rm ./build/BOOTX64.EFI
	rm ./build/bootloader.o
	rm ./build/bootloader.so
	rm ./build/kernel.elf
