#include "etatPorte.h"
#include "config.h"
#include "RFID.h"


/**
 * Fonction exécutée pendant l'état initial
 * éteint la LED et passe à l'état ATTENTE sur appui du bouton
 * @param aucun
 * @return aucun
 */
void EtatPorte() {
  if(machine.executeOnce) {
    Serial.println("Entrée dans l'ÉTAT PASSAGE DE LA PORTE");
  }
  int currentNodeMatrix = startNode[0];
  for (int i = 0; i < 36; i++) {
    if (pathdijk1[i] == currentNodeMatrix) {
      currentNodeMatrix = pathdijk1[i-1];
      break;
    }
  }

}
 
/**
 * Fonction de transition de l'état décodage vers l'état de passage de porte
 * @param aucun
 * @return true une fois que les differents chemins sont créé, false sinon
 */
bool transition_Porte_Haut() {
  return pathComplete;
}
bool transition_Porte_Bas() {
  return pathComplete;
}
bool transition_Porte_Gauche() {
  return pathComplete;
}
bool transition_Porte_Droite() {
  return pathComplete;
}