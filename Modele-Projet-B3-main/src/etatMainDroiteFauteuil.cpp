#include "etatMainDroiteFauteuil.h"
#include "config.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"
#include "pid_controller.h"
#include "gestionRGB.h"
#include "mainDroite.h"

void EtatMainDroiteFauteuil()
 {
    // À compléter : logique de l'état MainDroiteFauteuil
   mainDroiteFonctionnel();

}

bool transition_MainDroiteFauteuil_Fauteuil() 
{ viewColor();
    if(colorDetecte[2]>140.0)
    { 
        return true;
    }

    return false;
}

