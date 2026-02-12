#ifndef __COMM_H__
#define __COMM_H__

#define BUFF_LEN            40

typedef enum
{
    COMM_STATUS_IDLE = 0,
    COMM_STATUS_AVAIL,
    COMM_STATUS_NBR_OF
} comm_status_et;  

typedef struct
{
    uint8_t state;
    uint8_t buff[BUFF_LEN];
    uint8_t pos;
    comm_status_et status;
} buff_st;

typedef struct
{
    buff_st out;
    buff_st inp;
} comm_st;

void comm_initialize(void);

void comm_out_state_machine(void);

void comm_test_loop(void); 

#endif