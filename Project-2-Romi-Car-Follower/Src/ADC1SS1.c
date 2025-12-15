#include "ADC1SS1.h"
#include "tm4c123gh6pm.h"
void ADC1_SS1_Init(void){
  SYSCTL_RCGCADC_R |= 0x02;
  while((SYSCTL_RCGCADC_R & 0x02)==0){}
  SYSCTL_RCGCGPIO_R |= 0x10;
  while((SYSCTL_RCGCGPIO_R & 0x10)==0){}
  GPIO_PORTE_DIR_R &= ~0x07;
  GPIO_PORTE_DEN_R &= ~0x07;
  GPIO_PORTE_AMSEL_R |= 0x07;
  GPIO_PORTE_AFSEL_R |= 0x07;
  ADC1_ACTSS_R &= ~0x02;
  ADC1_PC_R = 0x01;
  ADC1_SSMUX1_R = (3<<0)|(2<<4)|(1<<8);
  ADC1_SSCTL1_R = 0x0600;
  ADC1_EMUX_R &= ~0x00F0;
  ADC1_IM_R &= ~0x02;
  ADC1_ACTSS_R |= 0x02;
}
void ADC1_In321(uint16_t *ain3, uint16_t *ain2, uint16_t *ain1){
  ADC1_PSSI_R = 0x02;
  while((ADC1_RIS_R & 0x02)==0){}
  *ain3 = ADC1_SSFIFO1_R & 0x0FFF;
  *ain2 = ADC1_SSFIFO1_R & 0x0FFF;
  *ain1 = ADC1_SSFIFO1_R & 0x0FFF;
  ADC1_ISC_R = 0x02;
}
uint16_t median(uint16_t u1,uint16_t u2,uint16_t u3){
  if(u1>u2){
    if(u2>u3) return u2;
    else if(u1>u3) return u3;
    else return u1;
  }else{
    if(u3>u2) return u2;
    else if(u1>u3) return u1;
    else return u3;
  }
}
void ReadADCMedianFilter321(uint16_t *front,uint16_t *left,uint16_t *right){
  static uint16_t f1=0,f2=0,l1=0,l2=0,r1=0,r2=0;
  uint16_t f,l,r;
  ADC1_In321(&f,&l,&r);
  *front = median(f,f1,f2);
  *left  = median(l,l1,l2);
  *right = median(r,r1,r2);
  f2=f1; f1=f;
  l2=l1; l1=l;
  r2=r1; r1=r;
}
