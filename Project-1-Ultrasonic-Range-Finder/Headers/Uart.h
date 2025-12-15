#ifndef UART_H
#define UART_H
#include <stdint.h>
#include "tm4c123gh6pm.h"
#define UART0_MASK 0x01
#define GPIO_PORTA 0x01
#define IBRD_CODE 17
#define FBRD_CODE 23
#define LCRH_CODE 0x70
#define CTL_CODE 0x301
void Uart_Init(void);
char Uart_Recieve(void);
void Uart_Transmit(uint8_t data);
void Uart_SendString(const char* str);
#endif
