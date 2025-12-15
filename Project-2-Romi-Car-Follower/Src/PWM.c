#include "PWM.h"
#include "tm4c123gh6pm.h"
#define FORWARD 0x88
void PWM_Init(void){
  SYSCTL_RCGCPWM_R |= 1;
  SYSCTL_RCGCGPIO_R |= 2;
  while((SYSCTL_RCGCGPIO_R & 2)==0){}
  GPIO_PORTB_DIR_R |= 0xB8;
  GPIO_PORTB_DEN_R |= 0xB8;
  GPIO_PORTB_AFSEL_R |= 0x30;
  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & ~0x00FF0000) | 0x00440000;
  PWM0_1_CTL_R = 0;
  PWM0_1_GENA_R = 0xC8;
  PWM0_1_GENB_R = 0xC08;
  PWM0_1_LOAD_R = 16000-1;
  PWM0_1_CTL_R |= 1;
  PWM0_ENABLE_R |= 0x0C;
}
void Duty(unsigned long l,unsigned long r){
  PWM0_1_CMPA_R = l-1;
  PWM0_1_CMPB_R = r-1;
}
void Forward(void){ GPIO_PORTB_DATA_R|=FORWARD; Duty(3200,3200); }
void Backward(void){ GPIO_PORTB_DATA_R&=~FORWARD; Duty(4800,4800); }
void SlowBackward(void){ GPIO_PORTB_DATA_R&=~FORWARD; Duty(2400,2400); }
void MoveLeft(void){ GPIO_PORTB_DATA_R|=FORWARD; Duty(4800,2400); }
void MoveRight(void){ GPIO_PORTB_DATA_R|=FORWARD; Duty(2400,4800); }
void PivotLeft(void){ GPIO_PORTB_DATA_R=0x08; Duty(4800,4800); }
void PivotRight(void){ GPIO_PORTB_DATA_R=0x80; Duty(4800,4800); }
void SlightLeft(void){ GPIO_PORTB_DATA_R|=FORWARD; Duty(3200,1600); }
void SlightRight(void){ GPIO_PORTB_DATA_R|=FORWARD; Duty(1600,3200); }
void Stop(void){ Duty(0,0); }
