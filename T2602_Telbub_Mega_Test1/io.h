#ifndef __IO_H__
#define __IO_H__
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


#define PORT_OUTX_DIR         DDRA    // Telbus --> Mega
#define PORT_OUTY_DIR         DDRC    // Telbus --> Mega
#define PORT_INPX_DIR         DDRL    // Mega --> Telbus 

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

void io_initialize(void);


#endif