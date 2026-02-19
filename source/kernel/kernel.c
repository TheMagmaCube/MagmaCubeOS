// kernel.c
static inline void outb(unsigned short port, unsigned char val){
    __asm__ volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline unsigned char inb(unsigned short port){
    unsigned char ret;
    __asm__ volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void serial_init(){
    outb(0x3F8 + 1, 0x00);
    outb(0x3F8 + 3, 0x80);
    outb(0x3F8 + 0, 0x03);
    outb(0x3F8 + 1, 0x00);
    outb(0x3F8 + 3, 0x03);
    outb(0x3F8 + 2, 0xC7);
    outb(0x3F8 + 4, 0x0B);
}

int serial_ready(){
    return inb(0x3F8 + 5) & 0x20;
}

void serial_write(char c){
    while(!serial_ready());
    outb(0x3F8, c);
}

void kprint(const char *s){
    while(*s) serial_write(*s++);
}

// Entry point kernela
void kmain(void){
    serial_init();
    kprint("HELLO SERIAL!\n");
    while(1); // zatrzymanie kernela
}
