#ifndef PWM_H
#define PWM_H
void PWM_Init(void);
void Duty(unsigned long left,unsigned long right);
void Forward(void);
void Backward(void);
void SlowBackward(void);
void MoveLeft(void);
void MoveRight(void);
void PivotLeft(void);
void PivotRight(void);
void SlightLeft(void);
void SlightRight(void);
void Stop(void);
#endif
