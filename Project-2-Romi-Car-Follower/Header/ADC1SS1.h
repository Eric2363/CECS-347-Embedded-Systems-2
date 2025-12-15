#ifndef ADC1SS1_H
#define ADC1SS1_H
#include <stdint.h>
void ADC1_SS1_Init(void);
void ADC1_In321(uint16_t *ain3, uint16_t *ain2, uint16_t *ain1);
uint16_t median(uint16_t u1, uint16_t u2, uint16_t u3);
void ReadADCMedianFilter321(uint16_t *front, uint16_t *left, uint16_t *right);
#endif
