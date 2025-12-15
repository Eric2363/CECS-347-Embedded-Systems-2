#include "timer1.h"
#include "tm4c123gh6pm.h"
void Timer1_Init(void){
  SYSCTL_RCGCTIMER_R |= TIMER1;
  while((SYSCTL_RCGCTIMER_R & TIMER1)==0){}
  TIMER1_CFG_R = MODE_16bit;
  Timer1A_Init();
  EchoTimer1_Init();
}
void Timer1A_Init(void){
  TIMER1_CTL_R &= ~TIMER1A_MASK;
  TIMER1_TAMR_R = PERIODIC_MODE;
  TIMER1_TAILR_R = MAX_RELOAD;
  TIMER1_TAPR_R = PRESCALE;
}
void delay(uint32_t ticks){
  TIMER1_TAILR_R = ticks;
  TIMER1_CTL_R |= TIMER1A_MASK;
  while(TIMER1_TAR_R != 0){}
}
void EchoTimer1_Init(void){
  TIMER1_CTL_R &= ~TIMER1A_MASK;
  TIMER1_TAMR_R = PERIODIC_MODE;
  TIMER1_TAILR_R = TIMERB_RELOAD;
  TIMER1_TAPR_R = PRESCALE_ECHO;
}
void Start_EchoTimer(void){
  TIMER1_CTL_R |= TIMER1A_MASK;
}
void Stop_EchoTimer(void){
  TIMER1_CTL_R &= ~TIMER1A_MASK;
}
uint32_t Get_Elapsed_MC(void){
  return TIMER1_TAILR_R - TIMER1_TAR_R;
}
