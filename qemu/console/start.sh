#!/bin/bash
/home/hubert/qemu/qemu_x64_exe/bin/qemu-system-x86_64 \
  -M q35 \
  -m 1G \
  -smp 1 \
  -cpu qemu64 \
  -net none \
  -drive if=pflash,format=raw,readonly=on,file=./OVMF_CODE.fd \
  -drive if=pflash,format=raw,file=./OVMF_VARS.fd \
  -drive file=./MagmaCubeOS.img,format=raw \
  -boot d \
  -nographic
