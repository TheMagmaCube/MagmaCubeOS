#!/bin/bash
/home/hubert/qemu/qemu_x64_exe/bin/qemu-system-x86_64 \
  -M pc \
  -m 2G \
  -smp 3 \
  -cpu qemu64 \
  -net none \
  -drive if=pflash,format=raw,readonly=on,file=./OVMF_CODE.fd \
  -drive if=pflash,format=raw,file=./OVMF_VARS.fd \
  -drive file=./MagmaCubeOS.img,format=raw \
  -boot d \
  -device VGA,romfile=./vgabios-stdvga.bin,rombar=0xC0000,vgamem_mb=16,mmio=off,qemu-extended-regs=off \
  -display gtk \
  -monitor tcp:127.0.0.1:4444,server,nowait \
  -serial stdio \
