// PID Controller Implementation
#include "pid_controller.h"
#include "gestionMoteur.h"
#include <Arduino.h>
// Working variables
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr, error;
double kp, ki, kd;

// pid_controller.cpp
double Compute(double Input, double Setpoint) {
    unsigned long now = millis();
    double timeChange = (double)(now - lastTime);

    error = Setpoint - Input;
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
    Setpoint = 15;
}
double getError()
{
    return error;
}

void AvancementRegule(double ultrasonGauche, double ultrasonDroite, double ultrasonArriere, double ultrasonAvant)
{
    double commande;
if (ultrasonGauche < 40)
{ 
commande = Compute(ultrasonGauche, 10);

  setSpeed1(-70 - commande);
  setSpeed2(-70 + commande);
  
}
else if (ultrasonDroite < 40)
{
  commande = Compute(ultrasonDroite, 30);
  setSpeed1(-70 + commande);
  setSpeed2(-70 - commande);
  
}
else
{
  setSpeed1(-70);
  setSpeed2(-70);
  
  
}
Avancer();
}
