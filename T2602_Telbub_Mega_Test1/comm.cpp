
#include "Arduino.h"
#include "comm.h"
#include "io.h"

comm_st comm = 
{
    .out =
    {
        .state = 0,
        .buff = {0},
        .pos = 0,
        .status=COMM_STATUS_IDLE,
    },
    .inp = 
    {
        .state = 0,
        .buff = {0},
        .pos = 0,
        .status=COMM_STATUS_IDLE,
    },
};

extern uint8_t pin_outy[8];
extern uint8_t pin_inpy[8];

void comm_initialize(void)
{

}


void comm_out_state_machine(void)
{
    switch(comm.out.state)
    {
        case 0:
            comm.out.state = 10;
            break;
        case 10:
            comm.out.state = 10;
            break;
        case 20:
            comm.out.state = 10;
            break;
        case 30:
            comm.out.state = 10;
            break;
    }

}

uint8_t out_data  = 0; 
uint8_t inp_data  = 0;
uint8_t inpy_indx = 0;
uint8_t state     = 0;
uint16_t iter     = 0;
unsigned long start_ms;


void comm_test_loop(void) 
{
    PORT_INPX_DATA_OUT = out_data;
    if (out_data < 63)  out_data++;
    else out_data = 0;
    delay(500);
    // inp_data = PORT_OUTX_DATA_IN;
    inp_data = PORT_OUTY_DATA_IN;
    Serial.println(inp_data,HEX);

    for(uint8_t i=0; i<8; i++){
        Serial.print(digitalRead(pin_outy[i]));
        Serial.print("-"); 
    } 
    Serial.println();

    for(uint8_t i=0; i<8; i++){
        if(i==inpy_indx) digitalWrite(pin_inpy[i], HIGH );
        else digitalWrite(pin_inpy[i], LOW );
    } 
    if(inpy_indx < 7) inpy_indx++; else inpy_indx=0;                                                              
}





void out_wr_data(uint8_t u8)
{
  PORT_DATA_OUT = u8;
  digitalWrite(PIN_OUT_READY, LOW);
  //Serial.print("out_wr_data "); Serial.println(u8);
}

// bool inp_is_data_avail(void)
// {
//   bool is_avail = false;
//   if (digitalRead(PIN_B_INP_AVAIL) == LOW)
//   {
//     is_avail = true;
//     //Serial.println("Data is available "); 
//   }
//   return is_avail;
// }

// uint8_t inp_rd_data(void)
// {
//     uint8_t inp_data = PORT_B_INP_DATA;
//     digitalWrite(PIN_B_INP_RDY, LOW);
//     //Serial.print("inp_rd_data "); Serial.println(inp_data);
//     return inp_data;
// }

// bool out_wr_ready(void)
// {
//   bool wr_ready = false;
//   if (digitalRead(PIN_A_OUT_ACK) == LOW)
//   {
//     wr_ready = true;
//     digitalWrite(PIN_A_OUT_RDY, HIGH);
//     digitalWrite(PIN_B_INP_RDY, HIGH);  
//     //Serial.println("out_wr_ready ");
//   }  
//   return wr_ready;

// }


// void loop() 
// {
//   bool do_loop = true;
  
//   //Serial.print("Start: "); Serial.println(millis());
//   start_ms = millis();
//   digitalWrite(PIN_A_OUT_ACK, HIGH);
//   digitalWrite(PIN_B_INP_RDY, HIGH);  

//   while(do_loop)
//   {
//     switch(state)
//     {
//       case 0:
//         state++;
//         break;
//       case 1:
//         out_wr_data(out_data);
//         state++;
//         break;
//       case 2:
//         if(inp_is_data_avail()) state++;
//         break;
//       case 3:
//         inp_data = inp_rd_data();
//         state++;
//         break;
//       case 4:
//         if (out_wr_ready()) state++;
//         break;
//       case 5:
//         out_data++;
//         //delay(1000);
//         if(++iter >= 1023) 
//         {
//           do_loop = false;
//           iter = 0;
//           out_data = 0;
//         }
//         state = 0;
//         break;
//     }
//     //Serial.print("State "); Serial.println(state);
//     //Serial.print("iter "); Serial.println(iter);
//   }
//   uint32_t duration_ms = millis()-start_ms;
//   Serial.print("Done: "); Serial.println(duration_ms);
//   //Serial.print("Done: "); Serial.println(millis());



//   //digitalWrite(PIN_A0, HIGH);
//   //digitalWrite(PIN_A0, LOW);
//   while(false)
//   {
//     //PORTF = out_cntr++;
//     // PORTF = 0xA5;
//     // PORTF = 0x5A;
//     // PORTF = 0xA5;
//     digitalWrite(PIN_A8, HIGH);
//     digitalWrite(PIN_A8, LOW);

//   }
// }

