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
    uint8_t master_vector_offset;
    uint8_t slave_vector_offset;

    uint8_t x86_mode;

    uint8_t IMR;

} pic;

pic pic_instance;

void pic_values_init(){

    //addresses

    pic_instance.PIC_Master_Command = 0x20;
    pic_instance.PIC_Master_Data = 0x21;

    pic_instance.PIC_Slave_Command = 0xA0;
    pic_instance.PIC_Slave_Data = 0xA1;

    //values

    //For both pic enabled
    //pic_instance.ICW1 = 0x11;

    //For only master pic enabled
    pic_instance.ICW1 = 0x13;

    pic_instance.master_vector_offset = 0x20;
    pic_instance.slave_vector_offset = 0x28;

    pic_instance.x86_mode = 0x01;

    //Value for enable access for IRQ0 line
    pic_instance.IMR = 0xFE;

}

void pic_init(){

    //ICW1
    pic_IO_out(pic_instance.PIC_Master_Command, pic_instance.ICW1);

    //ICW2
    pic_IO_out(pic_instance.PIC_Master_Data, pic_instance.master_vector_offset);

    //ICW3

    //ICW4
    pic_IO_out(pic_instance.PIC_Master_Data, pic_instance.x86_mode);

    //Enable access for IRQ0 line
    pic_IO_out(pic_instance.PIC_Master_Data, pic_instance.IMR);

}
