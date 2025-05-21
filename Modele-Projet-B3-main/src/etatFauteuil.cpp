#include "etatFauteuil.h"
#include "config.h"

void EtatFauteuil() 
{
    
    // À compléter : logique de l'état Fauteuil

}

bool transition_Fauteuil_MainDroite() 
{
   
    return false;
}

bool transition_Fauteuil_MainDroiteFauteuil() {
    if(PIN_MAIN_DROITE== HIGH)
    {
        return true;
    }
    return false;
}