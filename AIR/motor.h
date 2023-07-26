#ifndef MOTOR_H
#define MOTOR_H

#include "serv.h"

void TIMERS_PWM_INIT(void);
void controllEleron(int grad, int pos);
void setMotorSpeed(int speed);

#endif