#include "etatFauteuil.h"
#include "config.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"


void EtatFauteuil() 
{
    
    // À compléter : logique de l'état Fauteuil
  

}

bool transition_Fauteuil_MainDroiteFinal() 
{
   
       if(PIN_MAIN_DROITE== HIGH)
    {
        return true;
    }
    return false;
}
