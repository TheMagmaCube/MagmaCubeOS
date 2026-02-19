all:
	rm -f /home/hubert/os_source/build/kernel.elf
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c kernel.c -o /home/hubert/os_source/build/kernel.o
	ld -nostdlib -T link.ld -o /home/hubert/os_source/build/kernel.elf /home/hubert/os_source/build/kernel.o

	rm /home/hubert/os_source/build/kernel.o
