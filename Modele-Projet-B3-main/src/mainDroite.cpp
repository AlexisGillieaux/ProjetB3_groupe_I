#include <mainDroite.h>
#include <gestionUltrason.h>
#include <gestionRGB.h> 
#include <gestionMoteur.h>
#include "pid_controller.h"


int ultrasonDroite = 0;
int ultrasonGauche = 0;
int ultrasonDevant = 0;
int ultrasonArriere = 0;
float colorReel[3] = {0};
float colorDetecte[3] = {0};
// Constructeur par défaut
/**
 * @brief Fait avancer le robot vers l'avant en activant les moteurs dans le bon sens.
 *
 * Cette fonction configure les broches de contrôle des moteurs pour que le robot avance.
 *
 * @param Aucun paramètre n'est requis.
 * @return Cette fonction ne retourne aucune valeur.
 */
void Arret() 
{
    // Arrêter les moteurs
    digitalWrite(PIN_AIN1, LOW);  // Désactiver le moteur A dans le sens avant
    digitalWrite(PIN_AIN2, LOW);  // Désactiver le moteur A dans le sens arrière
    digitalWrite(PIN_BIN1, LOW);  // Désactiver le moteur B dans le sens avant
    digitalWrite(PIN_BIN2, LOW);  // Désactiver le moteur B dans le sens arrière
}
// void mainDroite(int ultrasonAvant, int ultrasonGauche, int ultrasonDroite) // Boucle principale
// {
//     bool fin; // Variable pour contrôler la boucle infinie
//     if(colorDetecte[0] == 0 && colorDetecte[1] == 255 && colorDetecte[2] == 0) // Vérifier si le bouton est pressé
//     {
//         fin = true; // Si la condition est remplie, mettre fin à la boucle infinie
//     }
//     else
//     {
//         fin = true; // Si la condition n'est pas remplie, mettre fin
//     }
//     while (fin == false) // Boucle infinie jusqu'à ce que fin soit vrai
//     {
//         if(ultrasonDroite<10) // Vérifier si le bouton est pressé
//         {
//             EnAvant(); // Appeler la fonction pour avancer en avant
//             delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
//             stop(); // Appeler la fonction pour arrêter le robot )
//         }
//         if (ultrasonDroite>10)
//         {
//             TournerDroite(); // Appeler la fonction pour tourner à droite
//             delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
//             stop(); // Appeler la fonction pour arrêter le robot
//         }
//         if(ultrasonDroite>10 && ultrasonAvant>10)
//         {
//             TournerGauche(); // Appeler la fonction pour tourner à gauche
//             delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
//             stop(); // Appeler la fonction pour arrêter le robot
//         }
     
//      delay(DELAI_BOUCLE_MS); // Attendre un certain temps avant de répéter la boucle
    
//     }
//     // Boucle principale
    
//     stop(); // Appeler la fonction pour arrêter le robot
// }

/**
 * @brief Contrôle le mouvement du robot en fonction des mesures des capteurs à ultrasons.
 *
 * Cette fonction ajuste la trajectoire du robot selon les distances mesurées par les capteurs ultrasoniques placés à l'arrière, à gauche, à droite et à l'avant.
 * - Si un obstacle est détecté à l'arrière et à gauche, le robot effectue une manœuvre d'évitement.
 * - Si un espace important est détecté à gauche, le robot tourne vers la gauche.
 * - Sinon, il avance en régulant sa trajectoire selon les mesures des capteurs.
 *
 * @param ultrasonGauche  Distance mesurée par le capteur ultrasonique gauche (en cm).
 * @param ultrasonDroite  Distance mesurée par le capteur ultrasonique droit (en cm).
 * @param ultrasonArriere Distance mesurée par le capteur ultrasonique arrière (en cm).
 * @param ultrasonDevant  Distance mesurée par le capteur ultrasonique avant (en cm).
 * @return void Cette fonction ne retourne aucune valeur.
 */
void mainDroiteFonctionnel()
{
if(ultrasonArriere<15 && ultrasonGauche<30)
  {
     delay(350);
     setSpeed1(-100);
     setSpeed2(100);
     Avancer();
      delay(500);
      setSpeed1(-80);
    setSpeed2(-80);
    Avancer();
    delay(400);
     
  }
  else if (ultrasonGauche>40 )
  {
   
    delay(350);
    setSpeed1(100);
    setSpeed2(-100);
    Avancer();
    delay(500);
    setSpeed1(-80);
    setSpeed2(-80);
    Avancer();
    delay(400);
    

  }
  else
  {
      AvancementRegule(ultrasonGauche, ultrasonDroite, ultrasonArriere, ultrasonDevant);
  }
}