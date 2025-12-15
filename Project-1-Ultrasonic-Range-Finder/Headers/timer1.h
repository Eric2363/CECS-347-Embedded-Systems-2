#ifndef TIMER1_H
#define TIMER1_H
#include <stdint.h>
#define TIMER1 0x02
#define MODE_16bit 0x04
#define PERIODIC_MODE 0x02
#define TIMER1A_MASK 0x01
#define MAX_RELOAD 159
#define PRESCALE 0
#define TIMERB_RELOAD 50666
#define PRESCALE_ECHO 12
void Timer1_Init(void);
void Timer1A_Init(void);
void EchoTimer1_Init(void);
void delay(uint32_t ticks);
void Start_EchoTimer(void);
void Stop_EchoTimer(void);
uint32_t Get_Elapsed_MC(void);
#endif
