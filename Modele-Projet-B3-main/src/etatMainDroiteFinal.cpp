#include "etatMainDroiteFinal.h"
#include "config.h"
#include "mainDroite.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"
#include "gestionRGB.h"
#include "pid_controller.h"

/**
 * @brief Gère la logique de l'état final de la main droite.
 * 
 * Cette fonction exécute les actions nécessaires lorsque l'état "MainDroiteFinal" est atteint.
 * 
 * @param Aucun paramètre.
 * @return Aucun retour.
 */
void EtatMainDroiteFinal() 
{
    // À compléter : logique de l'état MainDroiteFinal
       double ultrasonDroite = ultrasonicSensor4.measureDistanceCm();
   double ultrasonGauche = ultrasonicSensor1.measureDistanceCm();
   double ultrasonDevant = ultrasonicSensor2.measureDistanceCm();
   double ultrasonArriere = ultrasonicSensor3.measureDistanceCm();

   if(ultrasonArriere<13 && ultrasonGauche<30)
  {
     //delay(200);
     setSpeed1(-100);
     setSpeed2(100);
     Avancer();
      delay(500);
      setSpeed1(-75);
    setSpeed2(-75);
    Avancer();
    delay(700);
     
  }
  else if (ultrasonGauche>40 )
  {
   
    //delay(200);
    
    setSpeed1(100);
    setSpeed2(-100);
    Avancer();
    delay(500);
    if(ultrasonDroite>30)
    {
    setSpeed1(-85);
    setSpeed2(-70);
    Avancer();
    delay(800);
    }
    else{setSpeed1(-75);
    setSpeed2(-75);
    Avancer();
    delay(600);
  }
    
    
    

  }
  else
  {
      AvancementRegule(ultrasonGauche, ultrasonDroite, ultrasonArriere, ultrasonDevant);
  }
}

/**
 * @brief Vérifie la condition de transition de l'état MainDroiteFinal vers l'état Final.
 * 
 * Cette fonction évalue si la couleur détectée par le capteur 1 dépasse un seuil prédéfini.
 * 
 * @param colorDetecte Tableau de valeurs représentant les couleurs détectées par différents capteurs.
 * @return true si la valeur détectée par le capteur 1 est supérieure à 100.0, false sinon.
 */
bool transition_MainDroiteFinal_Final() 
{
    // À compléter : condition de transition
    if(colorDetecte[1]>100.0)
    { 
        return true;
    }
    return false;
}

