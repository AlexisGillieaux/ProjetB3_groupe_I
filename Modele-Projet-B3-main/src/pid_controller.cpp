// PID Controller Implementation
#include "pid_controller.h"
#include <Arduino.h>
// Working variables
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp, ki, kd;

// pid_controller.cpp
double Compute(double Input, double Setpoint) {
    unsigned long now = millis();
    double timeChange = (double)(now - lastTime);

    double error = Setpoint - Input;
    errSum += (error * timeChange);
    double dErr = (error - lastErr) / timeChange;

    double output = kp * error + ki * errSum + kd * dErr;

    lastErr = error;
    lastTime = now;
    return output;
}

// Function to set PID tunings
void SetTunings(double Kp, double Ki, double Kd) {
    kp = Kp;
    ki = Ki;
    kd = Kd;
    Setpoint = 0;
}