#include <mainDroite.h>
#include <gestionUltrason.h>
#include <gestionRGB.h> 


int ultrasonDroite = 0;
int ultrasonGauche = 0;
int ultrasonAvant = 0;
int ultrasonArriere = 0;
float colorReel[3] = {0};
float colorDetecte[3] = {0};
// Constructeur par défaut
void EnAvant() 
{
    // Avancer en avant
    digitalWrite(PIN_AIN2, HIGH); // Activer le moteur A dans le sens avant
    digitalWrite(PIN_AIN1, LOW);  // Désactiver le moteur A dans le sens arrière
    digitalWrite(PIN_BIN1, HIGH); // Activer le moteur B dans le sens avant
    digitalWrite(PIN_BIN2, LOW);  // Désactiver le moteur B dans le sens arrière
}
void TournerDroite() 
{
    // Tourner à droite
    digitalWrite(PIN_AIN1, HIGH); // Activer le moteur A dans le sens avant
    digitalWrite(PIN_AIN2, LOW);  // Désactiver le moteur A dans le sens arrière
    digitalWrite(PIN_BIN1, LOW);  // Désactiver le moteur B dans le sens avant
    digitalWrite(PIN_BIN2, HIGH); // Activer le moteur B dans le sens arrière
}
void TournerGauche() 
{
    // Tourner à gauche
    digitalWrite(PIN_AIN1, LOW);  // Désactiver le moteur A dans le sens avant
    digitalWrite(PIN_AIN2, HIGH); // Activer le moteur A dans le sens arrière
    digitalWrite(PIN_BIN1, HIGH); // Activer le moteur B dans le sens avant
    digitalWrite(PIN_BIN2, LOW);  // Désactiver le moteur B dans le sens arrière
}
void Arret() 
{
    // Arrêter les moteurs
    digitalWrite(PIN_AIN1, LOW);  // Désactiver le moteur A dans le sens avant
    digitalWrite(PIN_AIN2, LOW);  // Désactiver le moteur A dans le sens arrière
    digitalWrite(PIN_BIN1, LOW);  // Désactiver le moteur B dans le sens avant
    digitalWrite(PIN_BIN2, LOW);  // Désactiver le moteur B dans le sens arrière
}
void mainDroite(int ultrasonAvant, int ultrasonGauche, int ultrasonArriere, int ultrasonDroite) // Boucle principale
{
    bool fin; // Variable pour contrôler la boucle infinie
    if(colorDetecte[0] == 0 && colorDetecte[1] == 255 && colorDetecte[2] == 0) // Vérifier si le bouton est pressé
    {
        fin = true; // Si la condition est remplie, mettre fin à la boucle infinie
    }
    else
    {
        fin = true; // Si la condition n'est pas remplie, mettre fin
    }
    while (fin == false) // Boucle infinie jusqu'à ce que fin soit vrai
    {
        if(ultrasonDroite<20) // Vérifier si le bouton est pressé
        {
            EnAvant(); // Appeler la fonction pour avancer en avant
            delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
            stop(); // Appeler la fonction pour arrêter le robot )
        }
        if (ultrasonDroite>20)
        {
            TournerDroite(); // Appeler la fonction pour tourner à droite
            delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
            stop(); // Appeler la fonction pour arrêter le robot
        }
        if(ultrasonDroite>20 && ultrasonAvant>20)
        {
            TournerGauche(); // Appeler la fonction pour tourner à gauche
            delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
            stop(); // Appeler la fonction pour arrêter le robot
        }
     
     delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
    
    }
    // Boucle principale
    
    stop(); // Appeler la fonction pour arrêter le robot
}