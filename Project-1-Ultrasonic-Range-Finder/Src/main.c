#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "SysTick.h"
#include "PortF.h"
#include "timer1.h"
#include "portB.h"
#include "Uart.h"
#define PIN_B5_MASK 0x20
#define ECHO_VALUE 0x10
uint32_t distance;
volatile int done;
void Trigger(void);
int main(void){
  PLL_Init();
  PortF_Init();
  Timer1_Init();
  portB_Init();
  Uart_Init();
  SysTick_Init();
  while(1){
    done = 0;
    Trigger();
    while(!done){}
  }
}
void Trigger(void){
  GPIO_PORTB_DATA_R &= ~PIN_B5_MASK;
  delay(2);
  GPIO_PORTB_DATA_R |= PIN_B5_MASK;
  delay(10);
  GPIO_PORTB_DATA_R &= ~PIN_B5_MASK;
}
