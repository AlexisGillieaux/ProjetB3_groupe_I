#include <config.h>

// variables globales
extern int ultrasonDroite; // Variable pour stocker la distance mesurée par le capteur ultrason
extern int ultrasonGauche; // Variable pour stocker la distance mesurée par le capteur ultrason
extern int ultrasonAvant; // Variable pour stocker la distance mesurée par le capteur ultrason
extern int ultrasonArriere; // Variable pour stocker la distance mesurée par le capteur ultrason
extern float colorReel[3]; // Tableau pour stocker les valeurs RGB
extern float colorDetecte[3]; // Tableau pour stocker les valeurs RGB détectées
//constructeur par defaut
void EnAvant();
void TournerDroite();
void TournerGauche();
void mainDroite(int ultrasonAvant, int ultrasonGauche, int ultrasonDroite); // Boucle principale
void stop(); // Fonction pour arrêter le robot
void mainDroiteFonctionnel(); // Fonction principale pour le fonctionnement du robot
