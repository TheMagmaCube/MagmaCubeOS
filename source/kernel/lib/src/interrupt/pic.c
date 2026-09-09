//Main lib for PIC

//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{

    uint16_t PIC_Master_Command;
    uint16_t PIC_Master_Data;

    uint16_t PIC_Slave_Command;
    uint16_t PIC_Slave_Data;

} pic;

void pic_init(pic *pic_instance){

    pic_instance->PIC_Master_Command = 0x20;
    pic_instance->PIC_Master_Data = 0x21;

    pic_instance->PIC_Slave_Command = 0xA0;
    pic_instance->PIC_Slave_Data = 0xA1;

}
