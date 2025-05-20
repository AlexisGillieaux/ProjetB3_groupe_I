#include  "config.h"
#include  "gestionMoteur.h"

double speed1 = 100;
double speed2 = 80;
void setupMoteur() 
{
    pinMode(PIN_AIN1, OUTPUT); // Configurer la broche AIN1 comme sortie
    pinMode(PIN_AIN2, OUTPUT); // Configurer la broche AIN2 comme sortie
    pinMode(PIN_BIN1, OUTPUT); // Configurer la broche BIN1 comme sortie
    pinMode(PIN_BIN2, OUTPUT); // Configurer la broche BIN2 comme sortie
    analogWrite(PIN_AIN1, 0); // Initialiser la broche AIN1 à 0
    analogWrite(PIN_AIN2, 0); // Initialiser la broche AIN2 à 0
    analogWrite(PIN_BIN1, 0); // Initialiser la broche BIN1 à 0
    analogWrite(PIN_BIN2, 0); // Initialiser la broche BIN2 à 0
}
void Avancer() 
{   
    if(speed1 >= 0 && speed2 >= 0)
    {
        analogWrite(PIN_AIN1, 0); // Vitesse du moteur avant
        analogWrite(PIN_AIN2, speed2); // Vitesse du moteur avant
        analogWrite(PIN_BIN2, 0); // Vitesse du moteur avant     
        analogWrite(PIN_BIN1, speed1); // Vitesse du moteur avant
    }
    if (speed1 < 0 && speed2 < 0)
    {
        analogWrite(PIN_AIN1, -1*speed2); // Vitesse du moteur avant
        analogWrite(PIN_AIN2, 0); // Vitesse du moteur avant
        analogWrite(PIN_BIN2, -1*speed1); // Vitesse du moteur avant     
        analogWrite(PIN_BIN1, 0); // Vitesse du moteur avant
    }
    if (speed1 >= 0  && speed2 < 0)
    {
        analogWrite(PIN_AIN1, -1*speed2); // Vitesse du moteur avant
        analogWrite(PIN_AIN2, 0); // Vitesse du moteur avant
        analogWrite(PIN_BIN2, 0); // Vitesse du moteur avant     
        analogWrite(PIN_BIN1, speed1); // Vitesse du moteur avant
    }
    if(speed1 < 0 && speed2 >= 0)
    {
        analogWrite(PIN_AIN1, 0); // Vitesse du moteur avant
        analogWrite(PIN_AIN2, speed2); // Vitesse du moteur avant
        analogWrite(PIN_BIN2, -1*speed1); // Vitesse du moteur avant     
        analogWrite(PIN_BIN1, 0); // Vitesse du moteur avant
    }
    

    // // Avancer à une vitesse de 300
    // moteur.setSpeedA(speed1); // Vitesse du moteur avant
    // moteur.setSpeedB(speed2); // Vitesse du moteur avant
    // moteur.forwardA(); // Avancer
    // moteur.forwardB(); // Avancer
    // Serial.println("Avancer"); // Afficher "Avancer" dans le moniteur série
}
void Reculer() 
{
   
    analogWrite(PIN_AIN1, speed1); // Vitesse du moteur avant
    analogWrite(PIN_AIN2, 0); // Vitesse du moteur avant
    analogWrite(PIN_BIN2, speed2); // Vitesse du moteur avant
    analogWrite(PIN_BIN1, 0); // Vitesse du moteur avant

    // Reculer à une vitesse de 50
    // moteur.setSpeedA(speed1); // Vitesse du moteur reculer
    // moteur.backwardA(); // Reculer
    // moteur.setSpeedB(speed2); // Vitesse du moteur reculer
    // moteur.backwardB(); // Reculer
    // Serial.println("Reculer"); // Afficher "Reculer" dans le moniteur série

}
void tournerGauche() 
{
    analogWrite(PIN_AIN1, speed1); // Vitesse du moteur avant
    analogWrite(PIN_AIN2, 0); // Vitesse du moteur avant
    analogWrite(PIN_BIN1, speed2); // Vitesse du moteur avant
    analogWrite(PIN_BIN2, 0); // Vitesse du moteur avant
    // Tourner à gauche à une vitesse de 300
    // moteur.setSpeedA(speed1); // Vitesse du moteur avant
    // moteur.forwardA(); // Tourner à gauche
    // moteur.setSpeedB(speed2); // Vitesse du moteur avant
    // moteur.backwardB(); // Tourner à gauche
    // Serial.println("Tourner à gauche"); // Afficher "Tourner à gauche" dans le moniteur série
}
void tournerDroite() 
{
    analogWrite(PIN_AIN1, 0); // Vitesse du moteur reculer
    analogWrite(PIN_AIN2, speed2); // Vitesse du moteur reculer
    analogWrite(PIN_BIN1, 0); // Vitesse du moteur reculer
    analogWrite(PIN_BIN2, speed2); // Vitesse du moteur reculer
    // Tourner à droite à une vitesse de 300
    // moteur.setSpeedA(speed1); // Vitesse du moteur avant
    // moteur.backwardA();// Tourner à droite
    // moteur.setSpeedB(speed2); // Vitesse du moteur avant
    // moteur.forwardB(); // Tourner à droite
    // Serial.println("Tourner à droite"); // Afficher "Tourner à droite" dans le moniteur série
}

void Arreter() 
{
    analogWrite(PIN_AIN1, 0); // Vitesse du moteur avant
    analogWrite(PIN_AIN2, 0); // Vitesse du moteur avant
    analogWrite(PIN_BIN1, 0); // Vitesse du moteur avant
    analogWrite(PIN_BIN2, 0); // Vitesse du moteur avant
    // Arrêter le moteur
    // moteur.stop(); // Arrêter le moteur
    // Serial.println("Arrêter"); // Afficher "Arrêter" dans le moniteur série
}
// moteur gauche
double setSpeed1(double speed) 
{
   
    speed1 = speed; 
   
    return speed1;
}
//moteur droite
double setSpeed2(double speed) 
{
  
    speed2 = speed; // Vitesse du moteur reculer

    return speed2;
}

double getSpeed1() 
{
    return speed1; // Retourner la vitesse du moteur avant
}
double getSpeed2() 
{
    return speed2; // Retourner la vitesse du moteur reculer
}