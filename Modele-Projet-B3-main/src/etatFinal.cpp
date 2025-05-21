#include "etatFinall.h"
#include "gestionIR.h"

/**
 * Fonction exécutée pendant l'état final
 * Print de l'état, éteint la LED et attend que le bouton soit pressé
 * @param aucun
 * @return aucun
 */
void EtatFinall() 
{
    // À compléter : logique de l'état Final
     sendCode0(&sStoredIRData0);
    sendCode1(&sStoredIRData1);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(500);
    digitalWrite(PIN_BUZZER, LOW);
    delay(500);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(500);
    digitalWrite(PIN_BUZZER, LOW);
    delay(500);
}

/**
 * Fonction de transition de l'état final vers l'état initial
 * @param aucun
 * @return true si le bouton est pressé, false sinon
 */
bool transition_Final_Stop(){
    return true;
}
