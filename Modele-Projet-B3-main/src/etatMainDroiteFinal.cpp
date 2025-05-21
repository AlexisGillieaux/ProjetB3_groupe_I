#include "etatMainDroiteFinal.h"
#include "config.h"
#include "mainDroite.h"

void EtatMainDroiteFinal() 
{
    // À compléter : logique de l'état MainDroiteFinal
   mainDroiteFonctionnel();
}

bool transition_MainDroiteFinal_Final() 
{
    // À compléter : condition de transition
    if(colorDetecte[1]>100.0)
    { 
        return true;
    }
    return false;
}
bool transition_MainDroiteFinal_MainDroiteFauteuil() 
{
    if(PIN_MAIN_DROITE== HIGH)
    {
        return true;
    }
}