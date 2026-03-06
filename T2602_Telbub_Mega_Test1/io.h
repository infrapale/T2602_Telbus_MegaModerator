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


#define PORT_X_INP_DIR         DDRA    // Telbus --> Mega
#define PORT_Y_INP_DIR         DDRC    // Telbus --> Mega
#define PORT_X_OUT_DIR         DDRL    // Mega --> Telbus 

#define PORT_X_DATA_INP        PINA
#define PORT_Y_DATA_INP        PINC
#define PORT_X_DATA_OUT        PORTL

#define PORT_DATA_OUT          PORT_X_DATA_OUT
#define PORT_DATA_INP          PORT_X_DATA_INP

// Input Pins
#define PIN_Y_INP_0         37 
#define PIN_Y_INP_1         36 
#define PIN_Y_INP_2         35 
#define PIN_Y_INP_3         34 
#define PIN_Y_INP_4         33 
#define PIN_Y_INP_5         32 
#define PIN_Y_INP_6         31 
#define PIN_Y_INP_7         30 
// Output Pins
#define PIN_Y_OUT_0       A14
#define PIN_Y_OUT_1       A13
#define PIN_Y_OUT_2       A12
#define PIN_Y_OUT_3       A11
#define PIN_Y_OUT_4       41
#define PIN_Y_OUT_5       40
#define PIN_Y_OUT_6       39
#define PIN_Y_OUT_7       38

#define PIN_INP_RDY         PIN_Y_INP_7
#define PIN_INP_ACK         PIN_Y_OUT_6
#define PIN_OUT_RDY         PIN_Y_OUT_6
#define PIN_OUT_ACK         PIN_Y_INP_6

void io_initialize(void);
void io_read_out_x_y(void);
void io_get_byte(void);
void io_toggle_test(void);
void io_port_test(void);

#endif