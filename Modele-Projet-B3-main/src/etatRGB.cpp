#include "etatRGB.h"
#include "gestionRGB.h"

void EtatRGB() 
{
    viewColor();
}

bool transition_RGB_MainDroite() 
{
    // À compléter : condition de transition

}
bool transition_RGB_Fauteuil() {
    // À compléter : condition de transition
    if(colorDetecte[2] > 140.0)
    {
        return true;
    }
    return false;
}
bool transition_RGB_Porte() {
    // À compléter : condition de transition
    if(colorDetecte[0] > 140.0)
     {
        return true;
    }
    return false;
}
bool transition_RGB_Final() {
    // À compléter : condition de transition
   if(colorDetecte[1] > 100.0)
   {
        return true;
    }
    return false;
}
bool transition_RGB_MainDroiteFauteuil() {
    return true;
}