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
/**
 * @brief Calcule la sortie du contrôleur PID en fonction de l'entrée actuelle et de la consigne.
 *
 * Cette fonction met à jour l'intégrale et la dérivée de l'erreur, puis calcule la sortie PID.
 *
 * @param Input La valeur mesurée actuelle du système.
 * @param Setpoint La valeur cible que le système doit atteindre.
 * @return La sortie calculée du contrôleur PID.
 */
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
/**
 * @brief Sets the tuning parameters for the PID controller.
 *
 * This function updates the proportional (Kp), integral (Ki), and derivative (Kd) gains
 * used by the PID controller. It also sets the setpoint to 15.
 *
 * @param Kp The proportional gain.
 * @param Ki The integral gain.
 * @param Kd The derivative gain.
 * @return void
 */
void SetTunings(double Kp, double Ki, double Kd) {
    kp = Kp;
    ki = Ki;
    kd = Kd;
    Setpoint = 15;
}
/**
 * @brief Returns the current error value used by the PID controller.
 * 
 * @param None
 * @return double The current error value.
 */
double getError()
{
    return error;
}

/**
 * @brief Contrôle l'avancement régulé du robot en fonction des mesures des capteurs à ultrasons.
 *
 * Cette fonction ajuste la vitesse des moteurs pour maintenir une distance de sécurité
 * par rapport aux obstacles détectés par les capteurs à ultrasons situés à gauche, droite,
 * arrière et avant du robot. Elle applique une correction PID selon la proximité des obstacles
 * latéraux et avance normalement si aucun obstacle n'est détecté à proximité.
 *
 * @param ultrasonGauche  Distance mesurée par le capteur à ultrasons gauche (en cm).
 * @param ultrasonDroite  Distance mesurée par le capteur à ultrasons droit (en cm).
 * @param ultrasonArriere Distance mesurée par le capteur à ultrasons arrière (en cm).
 * @param ultrasonAvant   Distance mesurée par le capteur à ultrasons avant (en cm).
 * @return void
 */
void AvancementRegule(double ultrasonGauche, double ultrasonDroite, double ultrasonArriere, double ultrasonAvant)
{
    double commande;
  if (ultrasonGauche < 40)
  { 
  commande = Compute(ultrasonGauche, 10);

  setSpeed1(-65 - commande);
  setSpeed2(-65 + commande);
  
 }
else if (ultrasonDroite < 40)
 {
  commande = Compute(ultrasonDroite, 30);
  setSpeed1(-65 + commande);
  setSpeed2(-65 - commande);
  
    }
 else
 {
  setSpeed1(-60);
  setSpeed2(-75); 
 }
Avancer();
}


