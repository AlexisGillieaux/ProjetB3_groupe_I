// PID Controller Implementation
#include "pid_controller.h"
#include <Arduino.h>
// Working variables
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp, ki, kd;

// Function to compute the PID output
void Compute() {
    // How long since we last calculated
    unsigned long now = millis();
    double timeChange = (double)(now - lastTime);

    // Compute all the working error variables
    double error = Setpoint - Input;
    errSum += (error * timeChange);
    double dErr = (error - lastErr) / timeChange;

    // Compute PID Output
    Output = kp * error + ki * errSum + kd * dErr;

    // Remember some variables for next time
    lastErr = error;
    lastTime = now;
}

// Function to set PID tunings
void SetTunings(double Kp, double Ki, double Kd) {
    kp = Kp;
    ki = Ki;
    kd = Kd;
}