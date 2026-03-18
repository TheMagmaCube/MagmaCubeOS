all:
	rm -f ./build/kernel.elf
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c entry.s -o ./build/entry.o
	gcc -ffreestanding -m64 -O2 -mno-red-zone -mabi=ms -c kernel.c -o ./build/kernel.o
	ld -nostdlib -T link.ld -o ./build/kernel.elf ./build/entry.o ./build/kernel.o

	rm ./build/entry.o
	rm ./build/kernel.o
