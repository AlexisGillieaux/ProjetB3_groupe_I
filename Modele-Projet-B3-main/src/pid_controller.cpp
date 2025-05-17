// PID Controller Implementation
#include "pid_controller.h"
#include <Arduino.h>
// Working variables
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp, ki, kd;

// Function to compute the PID output
void Compute(float Input, double Output, double Setpoint) {
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
    Serial.println("PID Input: ");
    Serial.println(Input);
    Serial.print("PID Output: ");
    Serial.println(Output);
    Serial.print("Error: ");
    Serial.println(error);
}

// Function to set PID tunings
void SetTunings(double Kp, double Ki, double Kd) {
    kp = Kp;
    ki = Ki;
    kd = Kd;
    Setpoint = 0;
}