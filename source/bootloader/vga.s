.section .text
.global vga_text_mode

vga_text_mode:
    ##########################################
    # 1. Misc Output Register
    ##########################################

    mov $0x63, %al
    mov $0x3C2, %dx
    outb %al, %dx

    ##########################################
    # 2. Sequencer registers
    ##########################################

    mov $0x3C4, %dx

    mov $0x00, %al
    outb %al, %dx
    inc %dx
    mov $0x03, %al
    outb %al, %dx
    dec %dx

    mov $0x01, %al
    outb %al, %dx
    inc %dx
    mov $0x01, %al
    outb %al, %dx
    dec %dx

    mov $0x02, %al
    outb %al, %dx
    inc %dx
    mov $0x03, %al
    outb %al, %dx
    dec %dx

    mov $0x03, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x04, %al
    outb %al, %dx
    inc %dx
    mov $0x02, %al
    outb %al, %dx

    ##########################################
    # 3. Unlock CRTC
    ##########################################

    mov $0x3D4, %dx
    mov $0x11, %al
    outb %al, %dx
    inc %dx
    inb %dx, %al
    and $0x7F, %al
    outb %al, %dx
    dec %dx

    ##########################################
    # 4. CRTC registers (25 registers)
    ##########################################

    mov $0x3D4, %dx

    mov $0x00, %al
    outb %al, %dx
    inc %dx
    mov $0x5F, %al
    outb %al, %dx
    dec %dx

    mov $0x01, %al
    outb %al, %dx
    inc %dx
    mov $0x4F, %al
    outb %al, %dx
    dec %dx

    mov $0x02, %al
    outb %al, %dx
    inc %dx
    mov $0x50, %al
    outb %al, %dx
    dec %dx

    mov $0x03, %al
    outb %al, %dx
    inc %dx
    mov $0x82, %al
    outb %al, %dx
    dec %dx

    mov $0x04, %al
    outb %al, %dx
    inc %dx
    mov $0x55, %al
    outb %al, %dx
    dec %dx

    mov $0x05, %al
    outb %al, %dx
    inc %dx
    mov $0x81, %al
    outb %al, %dx
    dec %dx

    mov $0x06, %al
    outb %al, %dx
    inc %dx
    mov $0xBF, %al
    outb %al, %dx
    dec %dx

    mov $0x07, %al
    outb %al, %dx
    inc %dx
    mov $0x1F, %al
    outb %al, %dx
    dec %dx

    mov $0x08, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x09, %al
    outb %al, %dx
    inc %dx
    mov $0x4F, %al
    outb %al, %dx
    dec %dx

    mov $0x0A, %al
    outb %al, %dx
    inc %dx
    mov $0x0D, %al
    outb %al, %dx
    dec %dx

    mov $0x0B, %al
    outb %al, %dx
    inc %dx
    mov $0x0E, %al
    outb %al, %dx
    dec %dx

    mov $0x0C, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x0D, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x0E, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x0F, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x10, %al
    outb %al, %dx
    inc %dx
    mov $0x9C, %al
    outb %al, %dx
    dec %dx

    mov $0x11, %al
    outb %al, %dx
    inc %dx
    mov $0x8E, %al
    outb %al, %dx
    dec %dx

    mov $0x12, %al
    outb %al, %dx
    inc %dx
    mov $0x8F, %al
    outb %al, %dx
    dec %dx

    mov $0x13, %al
    outb %al, %dx
    inc %dx
    mov $0x28, %al
    outb %al, %dx
    dec %dx

    mov $0x14, %al
    outb %al, %dx
    inc %dx
    mov $0x1F, %al
    outb %al, %dx
    dec %dx

    mov $0x15, %al
    outb %al, %dx
    inc %dx
    mov $0x96, %al
    outb %al, %dx
    dec %dx

    mov $0x16, %al
    outb %al, %dx
    inc %dx
    mov $0xB9, %al
    outb %al, %dx
    dec %dx

    mov $0x17, %al
    outb %al, %dx
    inc %dx
    mov $0xA3, %al
    outb %al, %dx

    ##########################################
    # 5. Graphics Controller
    ##########################################

    mov $0x3CE, %dx

    mov $0x00, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x01, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x02, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x03, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x04, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    mov $0x05, %al
    outb %al, %dx
    inc %dx
    mov $0x10, %al
    outb %al, %dx
    dec %dx

    mov $0x06, %al
    outb %al, %dx
    inc %dx
    mov $0x0E, %al
    outb %al, %dx

    ##########################################
    # 6. Attribute Controller
    ##########################################

    inb $0x3DA, %al

    mov $0x3C0, %dx

    mov $0x00, %al
    outb %al, %dx
    mov $0x00, %al
    outb %al, %dx

    mov $0x01, %al
    outb %al, %dx
    mov $0x01, %al
    outb %al, %dx

    mov $0x02, %al
    outb %al, %dx
    mov $0x02, %al
    outb %al, %dx

    mov $0x03, %al
    outb %al, %dx
    mov $0x03, %al
    outb %al, %dx

    mov $0x04, %al
    outb %al, %dx
    mov $0x04, %al
    outb %al, %dx

    mov $0x05, %al
    outb %al, %dx
    mov $0x05, %al
    outb %al, %dx

    mov $0x06, %al
    outb %al, %dx
    mov $0x06, %al
    outb %al, %dx

    mov $0x07, %al
    outb %al, %dx
    mov $0x07, %al
    outb %al, %dx

    mov $0x08, %al
    outb %al, %dx
    mov $0x08, %al
    outb %al, %dx

    mov $0x09, %al
    outb %al, %dx
    mov $0x09, %al
    outb %al, %dx

    mov $0x0A, %al
    outb %al, %dx
    mov $0x0A, %al
    outb %al, %dx

    mov $0x0B, %al
    outb %al, %dx
    mov $0x0B, %al
    outb %al, %dx

    mov $0x0C, %al
    outb %al, %dx
    mov $0x0C, %al
    outb %al, %dx

    mov $0x0D, %al
    outb %al, %dx
    mov $0x0D, %al
    outb %al, %dx

    mov $0x0E, %al
    outb %al, %dx
    mov $0x0E, %al
    outb %al, %dx

    mov $0x0F, %al
    outb %al, %dx
    mov $0x0F, %al
    outb %al, %dx

    mov $0x10, %al
    outb %al, %dx
    mov $0x0C, %al
    outb %al, %dx

    mov $0x11, %al
    outb %al, %dx
    mov $0x00, %al
    outb %al, %dx

    mov $0x12, %al
    outb %al, %dx
    mov $0x0F, %al
    outb %al, %dx

    mov $0x13, %al
    outb %al, %dx
    mov $0x08, %al
    outb %al, %dx

    mov $0x14, %al
    outb %al, %dx
    mov $0x00, %al
    outb %al, %dx

    ##########################################
    ret
