#include "etatInitial.h"
#include "config.h"
#include "RFID.h"

/**
 * Fonction exécutée pendant l'état initial
 * éteint la LED et passe à l'état ATTENTE sur appui du bouton
 * @param aucun
 * @return aucun
 */
void EtatInitial() {
  if(machine.executeOnce) {
    Serial.println("Entrée dans l'ÉTAT INITIAL");
  }
  
  rfidddd();
  

}
 
/**
 * Fonction de transition de l'état initial vers l'état d'attente
 * @param aucun
 * @return true si le bouton est pressé, false sinon
 */
bool transition_Initial_Decodage() {
  return dataComplete;
}
