#include "Arduino.h"
#include "io.h"


uint8_t pin_outy[8] = { 
    PIN_OUTY_0_INP, PIN_OUTY_1_INP, PIN_OUTY_2_INP, PIN_OUTY_3_INP, 
    PIN_OUTY_4_INP, PIN_OUTY_5_INP, PIN_OUTY_6_INP, PIN_OUTY_7_INP 
};
uint8_t pin_inpy[8] = {
    PIN_INPY_0_OUT, PIN_INPY_1_OUT, PIN_INPY_2_OUT, PIN_INPY_3_OUT, 
    PIN_INPY_4_OUT, PIN_INPY_5_OUT, PIN_INPY_6_OUT, PIN_INPY_7_OUT
};

void io_initialize(void) 
{

    PORT_OUTX_DIR  = 0b0000000;  // Input !!
    PORT_OUTY_DIR  = 0b0000000;
    PORT_INPX_DIR  = 0b1111111;  // Output

    for(uint8_t i=0; i<8; i++){
        pinMode(pin_outy[i], INPUT); 
        pinMode(pin_inpy[i], OUTPUT); 
    } 
    digitalWrite(PIN_INP_ACK, HIGH);
    digitalWrite(PIN_OUT_ACK, HIGH); 
    

}
