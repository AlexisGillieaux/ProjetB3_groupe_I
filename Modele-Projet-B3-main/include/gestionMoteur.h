#include "config.h"
#include "L298NX2.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"

// Declaration des variables globales
extern double speed1; // Vitesse du moteur avant
extern double speed2; // Vitesse du moteur reculer


// Déclaration des fonctions
void Avancer();;
void Reculer();
void Arreter();
void tournerGauche();
void tournerDroite();