all:
	gcc -ffreestanding -m64 -O2 -mno-red-zone -c kernel.c -o /home/hubert/os_source/build/kernel.o
	ld -nostdlib -T link.ld -o /home/hubert/os_source/build/kernel.elf /home/hubert/os_source/build/kernel.o
