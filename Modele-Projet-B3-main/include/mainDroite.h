#include <config.h>

// variables globales
int ultrasonDroite = 0; // Variable pour stocker la distance mesurée par le capteur ultrason
int ultrasonGauche = 0; // Variable pour stocker la distance mesurée par le capteur ultrason
int ultrasonAvant = 0; // Variable pour stocker la distance mesurée par le capteur ultrason
int ultrasonArriere = 0; // Variable pour stocker la distance mesurée par le capteur ultrason
float colorReel[3]; // Tableau pour stocker les valeurs RGB
float colorDetecte[3]; // Tableau pour stocker les valeurs RGB détectées
//constructeur par defaut
void EnAvant();
void TournerDroite();
void TournerGauche();
void loop(int ultrasonAvant, int ultrasonGauche, int ultrasonArriere, int ultrasonDroite); // Boucle principale
void stop(); // Fonction pour arrêter le robot
