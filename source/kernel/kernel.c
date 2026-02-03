void kmain(void) {
    volatile char *video = (char*)0xB8000;
    video[0] = 'X';
    while(1);
}
