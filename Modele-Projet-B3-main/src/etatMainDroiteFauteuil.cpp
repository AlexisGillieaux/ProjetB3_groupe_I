#include "etatMainDroiteFauteuil.h"
#include "config.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"
#include "pid_controller.h"
#include "gestionRGB.h"
#include "mainDroite.h"

/**
 * @brief Gère l'état de la main droite lorsqu'elle interagit avec le fauteuil.
 *
 * Cette fonction appelle la logique associée à la fonctionnalité de la main droite
 * dans le contexte du fauteuil.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Cette fonction ne retourne aucune valeur.
 */
void EtatMainDroiteFauteuil()
 {
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
 * @brief Vérifie si la couleur détectée par la main droite sur le fauteuil dépasse un seuil spécifique.
 *
 * Cette fonction appelle viewColor() pour mettre à jour la détection de couleur, puis vérifie si la composante rouge (indice 2 de colorDetecte)
 * est supérieure à 140.0. Si c'est le cas, la transition est considérée comme valide.
 *
 * @param Aucun paramètre d'entrée.
 * @return true si la composante rouge détectée est supérieure à 140.0, false sinon.
 */
bool transition_MainDroiteFauteuil_Fauteuil() 
{ viewColor();
    if(colorDetecte[2]>140.0)
    { 
        return true;
    }

    return false;
}

