//Main lib for PIC

//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/interrupt/pic_IO_out.h"
#include "../../include/interrupt/pic_IO_in.h"

typedef struct{

    //addresses

    uint16_t PIC_Master_Command;
    uint16_t PIC_Master_Data;

    uint16_t PIC_Slave_Command;
    uint16_t PIC_Slave_Data;

    //values

    uint8_t ICW1;
    uint8_t first_irq;
    uint8_t eight_irq;

    uint8_t x86_mode;

} pic;

pic pic_instance;

void pic_values_init(){

    //addresses

    pic_instance.PIC_Master_Command = 0x20;
    pic_instance.PIC_Master_Data = 0x21;

    pic_instance.PIC_Slave_Command = 0xA0;
    pic_instance.PIC_Slave_Data = 0xA1;

    //values

    pic_instance.ICW1 = 0x11;
    pic_instance.first_irq = 0x20;
    pic_instance.eight_irq = 0x28;

    pic_instance.x86_mode = 0x01;

}

void pic_init(){

    //ICW1
    pic_IO_out(pic_instance.PIC_Master_Command, pic_instance.ICW1);

    //ICW2
    pic_IO_out(pic_instance.PIC_Master_Data, pic_instance.first_irq);

    //ICW3

    //ICW4
    pic_IO_out(pic_instance.PIC_Master_Data, pic_instance.x86_mode);



}
