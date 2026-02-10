/**


Telbus 1802       ---- Write ---->             Mega Mini
OUTX_DATA         ->  ------XXXXXXX----     -> PORT A
OUT_RDY OUTY.7    ->  HHHHHHHLLLHHHHHHH     -> PIN_INP_READY  PC7  (30) 
OUT_ACK INPY.7    <-  HHHHHHHHLLLHHHHHH     <- PIN_INP_ACK    PD7  (38)

Telbus 1802       <---- Read ----           Mega Mini
INPX_DATA         <-  ------XXXXXXX----     <- PORT L
INP_RDY  INPY.6   <-  HHHHHHHLLLHHHHHHH     <- PIN_OUT_READY  PG2  (39)
INP_ACK  OUTY.6   ->  HHHHHHHHLLLHHHHHH     -> PIN_OUT_ACK    PC6  (31)



Input Signals OUTX and OUTY   Telbus -> 
OUTX0   D22   PA0     OUTY0   D37   PC0
OUTX1   D23   PA1     OUTY1   D36   PC1
OUTX2   D24   PA2     OUTY2   D35   PC2
OUTX3   D25   PA3     OUTY3   D34   PC3
OUTX4   D26   PA4     OUTY4   D33   PC4
OUTX5   D27   PA5     OUTY5   D32   PC5
OUTX6   D28   PA6     OUTY6   D31   PC6
OUTX7   D29   PA7     OUTY7   D30   PC7

Output Signal INPX and INPY   Mega -> Telbus
INPX0   D49   PL0     INPY0   A14   PK6
INPX1   D48   PL1     INPY1   A13   PK5
INPX2   D47   PL2     INPY2   A12   PK4
INPX3   D46   PL3     INPY3   A11   PK3
INPX4   D45   PL4     INPY4   D41   PG0
INPX5   D44   PL5     INPY5   D40   PG1
INPX6   D43   PL6     INPY6   D39   PG2
INPX7   D42   PL7     INPY7   D38   PD7

**/

#include <Arduino.h>

// #define PIN_A0   A0
// #define PIN_A8   A8
#define PORT_OUTX_DIR         DDRA    // Telbus --> Mega
#define PORT_OUTY_DIR         DDRC    // Telbus --> Mega
#define PORT_INPX_DIR         DDRL    // Mega --> Telbus 

// #define PORT_INP_DIR          DDRK

#define PORT_OUTX_DATA_IN     PINA
#define PORT_OUTY_DATA_IN     PINC

#define PORT_INPX_DATA_OUT    PORTL

#define PORT_DATA_OUT          PORT_INPX_DATA_OUT
#define PORT_DATA_INP          PORT_OUTX_DATA_IN



// Input Pins
#define PIN_OUTY_0_INP       37 
#define PIN_OUTY_1_INP       36 
#define PIN_OUTY_2_INP       35 
#define PIN_OUTY_3_INP       34 
#define PIN_OUTY_4_INP       33 
#define PIN_OUTY_5_INP       32 
#define PIN_OUTY_6_INP       31 
#define PIN_OUTY_7_INP       30 
// Output Pins
#define PIN_INPY_0_OUT       A14
#define PIN_INPY_1_OUT       A13
#define PIN_INPY_2_OUT       A12
#define PIN_INPY_3_OUT       A11
#define PIN_INPY_4_OUT       41
#define PIN_INPY_5_OUT       40
#define PIN_INPY_6_OUT       39
#define PIN_INPY_7_OUT       38

#define PIN_INP_READY       PIN_OUTY_7_INP
#define PIN_INP_ACK         PIN_INPY_7_OUT 
#define PIN_OUT_READY       PIN_INPY_6_OUT
#define PIN_OUT_ACK         PIN_OUTY_6_INP

uint8_t pin_outy[8] = { 
    PIN_OUTY_0_INP, PIN_OUTY_1_INP, PIN_OUTY_2_INP, PIN_OUTY_3_INP, 
    PIN_OUTY_4_INP, PIN_OUTY_5_INP, PIN_OUTY_6_INP, PIN_OUTY_7_INP 
};
uint8_t pin_inpy[8] = {
    PIN_INPY_0_OUT, PIN_INPY_1_OUT, PIN_INPY_2_OUT, PIN_INPY_3_OUT, 
    PIN_INPY_4_OUT, PIN_INPY_5_OUT, PIN_INPY_6_OUT, PIN_INPY_7_OUT
};

void setup() 
{
  Serial.begin(9600);
  //pinMode(PIN_A0, OUTPUT);  
  // pinMode(PIN_A_OUT_RDY, OUTPUT);  
  // pinMode(PIN_A_OUT_ACK, INPUT);  
  // pinMode(PIN_B_INP_AVAIL, INPUT);  
  // pinMode(PIN_B_INP_RDY, OUTPUT);  
  // digitalWrite(PIN_A_OUT_ACK, HIGH);
  // digitalWrite(PIN_B_INP_RDY, HIGH); 
 
  // PORT_OUT_DIR  = 0b1111111;
  // PORT_INP_DIR  = 0b0000000;

  PORT_OUTX_DIR  = 0b0000000;  // Input !!
  PORT_OUTY_DIR  = 0b0000000;
  PORT_INPX_DIR  = 0b1111111;  // Output

  for(uint8_t i=0; i<8; i++){
      pinMode(pin_outy[i], INPUT); 
      pinMode(pin_inpy[i], OUTPUT); 
  } 
    

}

uint8_t out_data  = 0; 
uint8_t inp_data  = 0;
uint8_t inpy_indx = 0;
uint8_t state     = 0;
uint16_t iter     = 0;
unsigned long start_ms;


void loop() 
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


// #define PIN_INP_READY       PIN_OUTY_7_INP
// #define PIN_INP_ACK         PIN_INPY_7_OUT 
// #define PIN_OUT_READY       PIN_INPY_6_OUT
// #define PIN_OUT_ACK         PIN_OUTY_6_INP
// #define PORT_DATA_OUT          PORT_INPX_DATA_OUT
// #define PORT_DATA_INP          PORT_OUTX_DATA_IN



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

