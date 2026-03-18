#!/bin/bash
/home/hubert/qemu/qemu_x64_exe/bin/qemu-system-x86_64 \
  -M q35 \
  -m 2G \
  -smp 2 \
  -cpu qemu64 \
  -drive if=pflash,format=raw,readonly=on,file=./EFI/OVMF_CODE.fd \
  -drive if=pflash,format=raw,file=./EFI/OVMF_VARS.fd \
  -drive file=./efiboot.img,format=raw \
  -boot d \
  -display gtk \
  -serial stdio \
