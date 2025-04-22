#include "config.h"
#include "L298NX2.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"

// Declaration des variables globales
double speed1=80; // Vitesse du moteur avant
double speed2=40; // Vitesse du moteur reculer
L298NX2 moteur(PIN_AIN1, PIN_AIN2, PIN_BIN1, PIN_BIN2); // Initialisation du moteur avec les broches définies dans config.h
// L298NX2 moteur(PIN_AIN1, PIN_AIN2, PIN_BIN1, PIN_BIN2); 

// Déclaration des fonctions
void Avancer();;
void Reculer();
void Arreter();
void tournerGauche();
void tournerDroite();