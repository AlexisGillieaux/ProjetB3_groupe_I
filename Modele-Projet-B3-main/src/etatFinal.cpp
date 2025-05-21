#include "etatFinal.h"
#include "gestionIR.h"

/**
 * Fonction exécutée pendant l'état final
 * Print de l'état, éteint la LED et attend que le bouton soit pressé
 * @param aucun
 * @return aucun
 */
void EtatFinal() 
{
    // À compléter : logique de l'état Final
    sendCode0(&sStoredIRData0);
    sendCode1(&sStoredIRData1);
}

/**
 * Fonction de transition de l'état final vers l'état initial
 * @param aucun
 * @return true si le bouton est pressé, false sinon
 */
bool transition_Final_Initial() 
{
    // À compléter : condition de transition
    
    return true;
}

bool transition_Final_MainDroiteFauteuil() {
    return true;
}
