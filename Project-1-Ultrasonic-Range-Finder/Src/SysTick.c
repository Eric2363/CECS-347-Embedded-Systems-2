#include "tm4c123gh6pm.h"
#include "SysTick.h"
void SysTick_Init(void){
  NVIC_ST_CTRL_R = CLEAR_REG;
  NVIC_ST_RELOAD_R = HALF_SEC - 1;
  NVIC_ST_CURRENT_R = CLEAR_REG;
  NVIC_ST_CTRL_R = EN_SYSTICK;
}
