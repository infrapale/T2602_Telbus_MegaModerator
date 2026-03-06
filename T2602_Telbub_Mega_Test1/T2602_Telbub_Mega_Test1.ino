/*************************************************************************************
T2602_Telbus_Mega_Test

https://github.com/infrapale/T2602_Telbus_MegaModerator

*************************************************************************************/
#include <Arduino.h>
#include "main.h"
#include "io.h"
#include "comm.h"

void setup() 
{
    Serial.begin(9600);
    Serial3.begin(9600);
    io_initialize();
    comm_initialize();
    //io_get_byte();
}

void loop() 
{
    //comm_test_serial3();
    //io_read_out_x_y();
    //io_get_byte();
    //io_toggle_test();
    io_port_test();
}



