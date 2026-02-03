#!/bin/bash
/home/hubert/qemu/qemu_x64_exe/bin/qemu-system-x86_64 \
  -M q35 \
  -m 1G \
  -smp 1 \
  -cpu qemu64 \
  -drive if=pflash,format=raw,readonly=on,file=/home/hubert/qemu/EFI/OVMF_CODE.fd \
  -drive if=pflash,format=raw,file=/home/hubert/qemu/EFI/OVMF_VARS.fd \
  -drive file=efiboot.img,format=raw \
  -boot c \
  -nographic
  #-serial stdio \
  #-display none
  #-drive file=fat:rw:/home/hubert/qemu/EFI/X64BOOT,format=raw \
  #-boot menu=on \
