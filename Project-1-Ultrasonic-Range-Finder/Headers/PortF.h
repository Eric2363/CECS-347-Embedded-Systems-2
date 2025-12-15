#ifndef PORTF_H
#define PORTF_H
#include "tm4c123gh6pm.h"
#define PORTF_UNLOCK_CODE 0x4C4F434B
#define PORTF_CR_CODE 0x1F
#define GPIOF 0x20
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#define LEDS 0x0E
#define SW1 0x10
void PortF_Init(void);
#endif
