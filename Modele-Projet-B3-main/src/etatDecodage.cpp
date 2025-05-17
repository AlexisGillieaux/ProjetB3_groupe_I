#include "etatDecodage.h"
#include "config.h"
#include "RFID.h"


/**
 * Fonction exécutée pendant l'état initial
 * éteint la LED et passe à l'état ATTENTE sur appui du bouton
 * @param aucun
 * @return aucun
 */
void EtatDecodage() {
  if(machine.executeOnce) {
    Serial.println("Entrée dans l'ÉTAT DECODAGE");
  }
  int** nodes = (int**)malloc(36*sizeof(int*));
  int** matriceDecode = processMatrix(pointdata);
  free(pointdata); // Libérer la mémoire allouée pour le tableau de données
  nodes = matrixToNodes(matriceDecode);
  free(matriceDecode); // Libérer la mémoire allouée pour la matrice décodée
  int startNode[7] = {0, 0, 0, 0, 0, 0, 0}; // Initialiser avec des valeurs par défaut
  int goalNode[7] =  {0, 0, 0, 0, 0, 0, 0};  // Initialiser avec des valeurs par défaut
  int fauteuilNode[7] = {0, 0, 0, 0, 0, 0, 0}; // Initialiser avec des valeurs par défaut
  for (int j = 0; j < 36; j++) {

    if (nodes[j][3] == 1) { // Noeud de départ

      startNode[0] = nodes[j][0];
      startNode[1] = nodes[j][1];
      startNode[2] = nodes[j][2];
      startNode[3] = nodes[j][3];
      startNode[4] = nodes[j][4];
      startNode[5] = nodes[j][5];
      startNode[6] = nodes[j][6];
    }
    if (nodes[j][3] == 2) { // Noeud d'arrivée

      goalNode[0] = nodes[j][0];
      goalNode[1] = nodes[j][1];
      goalNode[2] = nodes[j][2];
      goalNode[3] = nodes[j][3];
      goalNode[4] = nodes[j][4];
      goalNode[5] = nodes[j][5];
      goalNode[6] = nodes[j][6];
    }
    if (nodes[j][3] == 4) { // Noeud fauteuil

      fauteuilNode[0] = nodes[j][0];
      fauteuilNode[1] = nodes[j][1];
      fauteuilNode[2] = nodes[j][2];
      fauteuilNode[3] = nodes[j][3];
      fauteuilNode[4] = nodes[j][4];
      fauteuilNode[5] = nodes[j][5];
      fauteuilNode[6] = nodes[j][6];
    }
  }
  int* dijkstraph1 = dijkstra(nodes, startNode);
  int* pathdijk1 = antecedant(dijkstraph1,fauteuilNode,startNode);
  free(dijkstraph1); // Libérer la mémoire allouée pour le tableau de noeuds précédents
  int* dijkstraph2 = dijkstra(nodes, fauteuilNode);
  int* pathdijk2 = antecedant(dijkstraph2,goalNode,fauteuilNode);
  free(dijkstraph2); // Libérer la mémoire allouée pour le tableau de noeuds précédents

  bool pathComplete = true;
  

}
 
/**
 * Fonction de transition de l'état décodage vers l'état de passage de porte
 * @param aucun
 * @return true une fois que les differents chemins sont créé, false sinon
 */
bool transition_Decodage_Porte() {
  return pathComplete;
}
