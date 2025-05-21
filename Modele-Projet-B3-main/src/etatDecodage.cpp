
#include "etatDecodage.h"
#include "config.h"
#include "RFID.h"


/**
 * Fonction exécutée pendant l'état de décodage.
 * Cette fonction traite les données de points, décode la matrice, extrait les noeuds de départ, d'arrivée et du fauteuil,
 * puis calcule les chemins optimaux à l'aide de l'algorithme de Dijkstra.
 * Elle libère également la mémoire allouée dynamiquement pour éviter les fuites.
 * 
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Aucun retour de valeur, la fonction effectue des traitements internes.
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
  int shortNode[7] = {0, 0, 0, 0, 0, 0, 0}; // Initialiser avec des valeurs par défaut
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
    if(nodes[j][3] == 3) { // Noeud court

      shortNode[0] = nodes[j][0];
      shortNode[1] = nodes[j][1];
      shortNode[2] = nodes[j][2];
      shortNode[3] = nodes[j][3];
      shortNode[4] = nodes[j][4];
      shortNode[5] = nodes[j][5];
      shortNode[6] = nodes[j][6];
    }
  }
  int* dijkstraph1 = dijkstra(nodes, startNode);
  int* pathdijk1 = antecedant(dijkstraph1,shortNode,startNode);
  int* instruction1 = seqInstruct2(pathdijk1,startNode);
  free(dijkstraph1); // Libérer la mémoire allouée pour le tableau de noeuds précédents
  int* dijkstraph2 = dijkstra(nodes, shortNode);
  int* pathdijk2 = antecedant(dijkstraph2,fauteuilNode,shortNode);
  int* instruction2 = seqInstruct2(pathdijk2,shortNode);
  free(dijkstraph2); // Libérer la mémoire allouée pour le tableau de noeuds précédents
  int* diijkstraph3 = dijkstra(nodes, fauteuilNode);
  int* pathdijk3 = antecedant(diijkstraph3,goalNode,fauteuilNode);
  int* instruction3 = seqInstruct2(pathdijk3,fauteuilNode);
  free(diijkstraph3); // Libérer la mémoire allouée pour le tableau de noeuds précédents

  bool pathComplete = true;
  

}
 
/**
 * Fonction de transition de l'état décodage vers l'état de passage de porte.
 * Vérifie si les différents chemins ont été créés pour permettre la transition.
 * 
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return true si les chemins sont créés et la transition peut avoir lieu, false sinon.
 */
bool transition_Decodage_Porte() 
{
  if(pathComplete==true)
  {return true;}
  
  return true;
}
/**
 * Fonction de transition de l'état décodage vers l'état main droite.
 * Vérifie si les différents chemins ont été créés pour permettre la transition.
 * 
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return true si le bouton mainDroite et la transition peut avoir lieu, false sinon.
 */
bool transition_Decodage_MainDroiteFauteuil() 
{
    if(PIN_MAIN_DROITE== HIGH)
    {
        return true;
    }
    return false;
}
