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
    io_initialize();
    comm_initialize();
}

void loop() 
{
    comm_test_loop();
}



