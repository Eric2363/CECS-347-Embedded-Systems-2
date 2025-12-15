#ifndef PORTF_H
#define PORTF_H
#include "tm4c123gh6pm.h"
#define PORTF 0x20
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#define LEDS 0x0E
#define SW1 0x10
#define SW2 0x01
#define SWITCHES (SW1|SW2)
#define LEVEL1 (1<<21)
void PortF_Init(void);
#endif
