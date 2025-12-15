#include "Uart.h"
void Uart_Init(void){
  SYSCTL_RCGCUART_R |= UART0_MASK;
  SYSCTL_RCGCGPIO_R |= GPIO_PORTA;
  UART0_CTL_R = 0;
  UART0_IBRD_R = IBRD_CODE;
  UART0_FBRD_R = FBRD_CODE;
  UART0_LCRH_R = LCRH_CODE;
  UART0_CTL_R = CTL_CODE;
  GPIO_PORTA_DEN_R |= 0x03;
}
char Uart_Recieve(void){
  while(UART0_FR_R & UART_FR_RXFE){}
  return (char)(UART0_DR_R & 0xFF);
}
void Uart_Transmit(uint8_t data){
  while(UART0_FR_R & UART_FR_TXFF){}
  UART0_DR_R = data;
}
void Uart_SendString(const char* str){
  while(*str){ Uart_Transmit(*str++); }
}
