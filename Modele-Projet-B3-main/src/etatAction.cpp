#include "etatAction.h"

/**
 * Fonction exécutée pendant l'état d'action
 * Clignottement rapide de la LED 
 * passe à l'état FINAL après 5 secondes
 * @param aucun
 * @return aucun
 */
void EtatAction() {

  if(machine.executeOnce){
    Serial.println("Entrée dans l'ÉTAT ACTION");
    digitalWrite(PIN_LED, LOW);
    tempsDebut = millis();
  }

  // Mettre à jour l'état du bouton (même si on ne l'utilise pas dans cet état)
  bouton.read();
  
  // Faire clignoter la LED rapidement
  digitalWrite(PIN_LED, (millis() / 100) % 2);
}

// Après 5 secondes, passer à l'état final
bool transition_Action_Final(){
  return (millis() - tempsDebut >= DELAI_ACTION);
}
