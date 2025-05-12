#include "config.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"
#include "etatFinal.h"
#include "matrice.h"
#include "algo.h"
#include "gestionRGB.h"
#include <IRremote.hpp>
#include "IR.h"
#include "gestionRFID.h"
#include <gestionIR.h>


// Définition des variables globales
int i = 0;
StateMachine machine = StateMachine();
Button bouton(PIN_BOUTON);
unsigned long tempsDebut = 0;
//MFRC522 mfrc522(PIN_SS, PIN_RST);
UltraSonicDistanceSensor ultrasonicSensor1(PIN_TRIGGER_1, PIN_ECHO_1);
UltraSonicDistanceSensor ultrasonicSensor2(PIN_TRIGGER_2, PIN_ECHO_2);
UltraSonicDistanceSensor ultrasonicSensor3(PIN_TRIGGER_3, PIN_ECHO_3);
UltraSonicDistanceSensor ultrasonicSensor4(PIN_TRIGGER_4, PIN_ECHO_4);
DFRobot_TCS34725 tcs(&Wire, ADDRESS_TCS34725, TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
L298NX2 moteur(PIN_AIN1, PIN_AIN2, PIN_BIN1, PIN_BIN2);
int* matriceNonDecode = (int*)malloc(13 * 13 * sizeof(int)); 
char matriceNonDecodeChar[] = "1111111111111112010041000111101011101011010100000101101011111110110100000000011011111111101100000001003110101111101311010100000121101110111110110000000000011111111111111";
int** nodes = (int**)malloc(36*sizeof(int*));




// Création des états
State* etatInitial = machine.addState(&EtatInitial);
State* etatAttente = machine.addState(&EtatAttente);
State* etatAction = machine.addState(&EtatAction);
State* etatFinal = machine.addState(&EtatFinal);

void setup() {
  // Initialisation de la communication série
   Serial.begin(9600);
  // SPI.begin();
  // mfrc522.PCD_Init();
  //connexion();
  //rfid_init();
  
  

  Serial.println("Démarrage de la machine d'état");
  
  // Configuration des broches
  pinMode(PIN_LED, OUTPUT);
  setupReceiveIR();
  // Pas besoin de configurer PIN_BOUTON car la librairie Button s'en charge
  
  // Configuration des transitions
  etatInitial->addTransition(&transition_Initial_Attente, etatAttente);
  etatAttente->addTransition(&transition_Attente_Action, etatAction);
  etatAction->addTransition(&transition_Action_Final, etatFinal);
  etatFinal->addTransition(&transition_Final_Initial, etatInitial);

  // Démarrer la machine dans l'état initial
  //machine.run();
}

void loop() {
  receiveIRData();
  //Serial.println("Initialisation du capteur de couleur");

  //rfidddd();
  // Mettre à jour la machine d'état
  //machine.run();
  // if (i ==0){
  //   Serial.println("Matrice non traitée :");
  //   for (int j = 0; j < 169; j++)
  //   {
  //       matriceNonDecode[j] = matriceNonDecodeChar[j] - '0';
  //   }
  //   for (size_t i = 0; i < 169; i++)
  //   {
  //     Serial.print(matriceNonDecode[i]);
  //   }
  //   Serial.println();
    
  //   int** matriceDecode = processMatrix(matriceNonDecode);
  //   Serial.println("Matrice traitée :");
  //   for (int j = 0; j < 13; j++) {
  //     for (int k = 0; k < 13; k++) {
  //       Serial.print(matriceDecode[j][k]);
  //       Serial.print(" ");
  //     }
  //     Serial.println();
  //   }
  //   // Serial.println("Listes des noeuds :");
  //   nodes = matrixToNodes(matriceDecode);
  //   for (int j = 0; j < 36; j++){
  //     Serial.print("Noeud ");
  //     Serial.print(nodes[j][0]);
  //     Serial.print(" : ");
  //     Serial.print(nodes[j][1]);
  //     Serial.print(" ");
  //     Serial.print(nodes[j][2]);
  //     Serial.print(" ");
  //     Serial.print(nodes[j][3]);
  //     Serial.print(" ");
  //     Serial.print(nodes[j][4]);
  //     Serial.print(" ");
  //     Serial.print(nodes[j][5]);
  //     Serial.print(" ");
  //     Serial.print(nodes[j][6]);
  //     Serial.print(" ");
  //     Serial.println(nodes[j][7]);
  //   }
  //   // Définir les noeuds de départ et d'arrivée
  //   int startNode[7] = {0, 0, 0, 0, 0, 0, 0}; // Initialiser avec des valeurs par défaut
  //   int goalNode[7] =  {0, 0, 0, 0, 0, 0, 0};  // Initialiser avec des valeurs par défaut

  //   // Trouver les coordonnées des noeuds de départ et d'arrivée
  //   for (int j = 0; j < 36; j++) {
  //     if (nodes[j][3] == 1) { // Noeud de départ
  //       startNode[0] = nodes[j][0];
  //       startNode[1] = nodes[j][1];
  //       startNode[2] = nodes[j][2];
  //       startNode[3] = nodes[j][3];
  //       startNode[4] = nodes[j][4];
  //       startNode[5] = nodes[j][5];
  //       startNode[6] = nodes[j][6];
  //       // Serial.print("Noeud de depart ");
  //       // Serial.print(nodes[j][0]);
  //       // Serial.print(" : ");
  //       // Serial.print(nodes[j][1]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][2]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][3]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][4]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][5]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][6]);
  //       // Serial.print(" ");
  //       // Serial.println(nodes[j][7]);
  //     }
  //     if (nodes[j][3] == 2) { // Noeud d'arrivée
  //       goalNode[0] = nodes[j][0];
  //       goalNode[1] = nodes[j][1];
  //       goalNode[2] = nodes[j][2];
  //       goalNode[3] = nodes[j][3];
  //       goalNode[4] = nodes[j][4];
  //       goalNode[5] = nodes[j][5];
  //       goalNode[6] = nodes[j][6];
  //       // Serial.print("Noeud d'arriver ");
  //       // Serial.print(nodes[j][0]);
  //       // Serial.print(" : ");
  //       // Serial.print(nodes[j][1]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][2]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][3]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][4]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][5]);
  //       // Serial.print(" ");
  //       // Serial.print(nodes[j][6]);
  //       // Serial.print(" ");
  //       // Serial.println(nodes[j][7]);
  //     }
  //   }
        
  // //   // Appeler la fonction A* et afficher les résultats
  // //   //int** chemin = aStar(matriceDecode, startNode, goalNode);
  // //   // Reconstruire et afficher le chemin parcouru

  //   int* cheminReconstruit = path( dijkstra(nodes, startNode), startNode, goalNode);
  //   int* dijkstraph = dijkstra(nodes, startNode);
  //   Serial.println("Liste d'antecedants :");
  //   for (int j = 0; j < 36; j++) {
  //     Serial.print(dijkstraph[j]);
  //     Serial.print(" ");
  //   }
  //   Serial.println("Chemin reconstruit :");
  //   for (int j = 0; j < 36; j++) {
  //     Serial.print(cheminReconstruit[j]);
  //     Serial.print(" ");
  //   }

  //   // Libérer la mémoire allouée pour le chemin reconstruit
  //   free(cheminReconstruit);

  //   // Libérer la mémoire allouée pour le chemin
  //   //free(chemin);
  //   free(nodes); // Libérer la mémoire allouée
  //   free(matriceDecode); // Libérer la mémoire allouée
  //   i++;
  //   //viewColor();
  // }
  
  // Petit délai pour éviter une utilisation excessive du CPU
  delay(DELAI_BOUCLE_MS);
}
