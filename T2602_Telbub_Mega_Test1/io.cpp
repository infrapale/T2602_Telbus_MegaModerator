#include "Arduino.h"
#include "io.h"


uint8_t pin_y_inp[8] = { 
    PIN_Y_INP_0, PIN_Y_INP_1, PIN_Y_INP_2, PIN_Y_INP_3, 
    PIN_Y_INP_4, PIN_Y_INP_5, PIN_Y_INP_6, PIN_Y_INP_7 
};
uint8_t pin_y_out[8] = {
    PIN_Y_OUT_0, PIN_Y_OUT_1, PIN_Y_OUT_2, PIN_Y_OUT_3, 
    PIN_Y_OUT_4, PIN_Y_OUT_5, PIN_Y_OUT_6, PIN_Y_OUT_7
};

void io_initialize(void) 
{
    PORT_X_INP_DIR  = 0b0000000;  // Input !!
    PORT_Y_INP_DIR  = 0b0000000;
    PORT_X_OUT_DIR  = 0b1111111;  // Output

    for(uint8_t i=0; i<8; i++){
        pinMode(pin_y_inp[i], INPUT); 
        pinMode(pin_y_out[i], OUTPUT); 
    } 
    digitalWrite(PIN_INP_ACK, HIGH);
    digitalWrite(PIN_OUT_RDY, HIGH);     
}

void io_read_out_x_y(void)
{
    uint8_t inp_x  = 0;
    uint8_t inp_y  = 0;
    for(uint16_t n = 0; n < 10; n++ )
    {
        inp_x = PORT_X_DATA_INP;
        inp_y = PORT_Y_DATA_INP;
        Serial.print(inp_x,HEX);
        Serial.print("--");
        Serial.println(inp_y,HEX);
        //delay(1000);

    }
}

void io_get_byte(void)
{
    uint8_t inp_x  = 0;
    uint8_t inp_y  = 0;
    digitalWrite(PIN_INP_ACK,HIGH);
    uint16_t n = 100;
    while(n > 0)
    {
        inp_y = PORT_Y_DATA_INP;
        inp_x = PORT_X_DATA_INP;
        if (digitalRead(PIN_INP_RDY) == 0x00){
            digitalWrite(PIN_INP_ACK,LOW);
            Serial.print("I got: "); Serial.println(inp_x,HEX);
            delay(1);
            digitalWrite(PIN_INP_ACK,HIGH);
            n--;
        }

        Serial.print(inp_x,HEX);
        Serial.print("--");
        Serial.println(digitalRead(PIN_INP_RDY));
        //Serial.println(inp_y,HEX);
        delay(100);

    }

}
void io_toggle_test(void)
{
    while(true){
        digitalWrite(PIN_INP_ACK,HIGH);
        delay(10);
        digitalWrite(PIN_INP_ACK,LOW);
        delay(10);
    }
}

uint8_t u8_out = 0x00;
uint8_t u8_inpx = 0x00;
uint8_t u8_inpy = 0x00;

void io_port_test(void)
{
    while(true){
        PORT_X_DATA_OUT = u8_out;
        //delay(1);
        u8_inpx = PORT_X_DATA_INP;
        u8_inpy = PORT_Y_DATA_INP;
        Serial.print(u8_out,HEX);Serial.print(" X: "); Serial.print(u8_inpx,HEX);
        Serial.print(" Y: "); Serial.println(u8_inpy,HEX);
        u8_out++;
        delay(10);

    }
}