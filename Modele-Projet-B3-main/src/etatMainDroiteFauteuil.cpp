#include "etatMainDroiteFauteuil.h"
#include "config.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"
#include "pid_controller.h"
#include "gestionRGB.h"

void EtatMainDroiteFauteuil()
 {
    // À compléter : logique de l'état MainDroiteFauteuil
    double ultrasonGauche = ultrasonicSensor1.measureDistanceCm();
    double ultrasonDroite = ultrasonicSensor4.measureDistanceCm();
    double ultrasonArriere = ultrasonicSensor3.measureDistanceCm();
    double ultrasonAvant = ultrasonicSensor2.measureDistanceCm();
    AvancementRegule(ultrasonGauche, ultrasonDroite, ultrasonArriere, ultrasonAvant);

}

bool transition_MainDroiteFauteuil_Fauteuil() 
{ viewColor();
    if(colorDetecte[0]>140.0)
    { 
        return true;
    }

    return false;
}

