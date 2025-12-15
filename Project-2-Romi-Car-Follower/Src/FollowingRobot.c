#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "ADC1SS1.h"
#include "PWM.h"
#include "PortF.h"
#include "PLL.h"
enum robot_modes{INACTIVE,OBJECT_FOLLOWER,WALL_FOLLOWER};
volatile enum robot_modes mode=INACTIVE;
extern void DisableInterrupts(void);
extern void EnableInterrupts(void);
extern void WaitForInterrupt(void);
void System_Init(void);
int main(void){
  System_Init();
  while(1){
    if(mode==OBJECT_FOLLOWER) Forward();
    else if(mode==WALL_FOLLOWER) MoveLeft();
    else{ Stop(); WaitForInterrupt(); }
  }
}
void System_Init(void){
  DisableInterrupts();
  PLL_Init();
  ADC1_SS1_Init();
  PWM_Init();
  PortF_Init();
  EnableInterrupts();
}
