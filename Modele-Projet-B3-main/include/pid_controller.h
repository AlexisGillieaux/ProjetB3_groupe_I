#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H
#include "config.h"

// PID Controller Header File

// Function prototypes
double Compute(double Input, double Setpoint);
void SetTunings(double Kp, double Ki, double Kd);
double getError();
void AvancementRegule(double ultrasonGauche, double ultrasonDroite, double ultrasonArriere, double ultrasonAvant);

// External variables
extern unsigned long lastTime;
extern double Input, Output, Setpoint;
extern double errSum, lastErr;
extern double kp, ki, kd;

#endif // PID_CONTROLLER_H