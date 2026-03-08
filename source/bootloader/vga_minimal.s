.section .text
.global vga_text_mode

vga_text_mode:
    ##########################################
    # 1. Misc Output Register (0x3C2)
    ##########################################
    mov $0x67, %al       # standard 80x25 color, 25 lines
    mov $0x3C2, %dx
    outb %al, %dx

    ##########################################
    # 2. Sequencer (0x3C4/0x3C5)
    ##########################################
    mov $0x3C4, %dx

    # Reset
    mov $0x00, %al
    outb %al, %dx
    mov $0x03, %al
    outb %al, %dx

    # Clocking mode
    mov $0x01, %al
    outb %al, %dx
    mov $0x01, %al
    outb %al, %dx

    # Map mask
    mov $0x02, %al
    outb %al, %dx
    mov $0x03, %al
    outb %al, %dx

    # Character map select
    mov $0x03, %al
    outb %al, %dx
    mov $0x00, %al
    outb %al, %dx

    # Memory mode
    mov $0x04, %al
    outb %al, %dx
    mov $0x02, %al
    outb %al, %dx

    ##########################################
    # 3. CRTC (0x3D4/0x3D5) minimal to B8000
    ##########################################
    mov $0x3D4, %dx

    # Horizontal total
    mov $0x00, %al
    outb %al, %dx
    inc %dx
    mov $0x5F, %al
    outb %al, %dx
    dec %dx

    # Horizontal display end
    mov $0x01, %al
    outb %al, %dx
    inc %dx
    mov $0x4F, %al
    outb %al, %dx
    dec %dx

    # Start address high
    mov $0x0C, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx
    dec %dx

    # Start address low
    mov $0x0D, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx

    ##########################################
    # 4. Attribute Controller (0x3C0)
    # Turn on video and flip-flop
    ##########################################
    inb $0x3DA, %al      # flip-flop

    mov $0x3C0, %dx
    mov $0x00, %al
    outb %al, %dx        # palet 0
    mov $0x0F, %al
    outb %al, %dx        # video enable

    ##########################################
    # 5. Graphics Controller minimal (0x3CE/0x3CF)
    ##########################################
    mov $0x3CE, %dx
    mov $0x05, %al
    outb %al, %dx
    inc %dx
    mov $0x00, %al
    outb %al, %dx

    ret
