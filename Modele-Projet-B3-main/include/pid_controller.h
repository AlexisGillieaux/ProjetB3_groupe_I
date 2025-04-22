#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H
#include "config.h"

// PID Controller Header File

// Function prototypes
void Compute();
void SetTunings(double Kp, double Ki, double Kd);

// External variables
extern unsigned long lastTime;
extern double Input, Output, Setpoint;
extern double errSum, lastErr;
extern double kp, ki, kd;

#endif // PID_CONTROLLER_H