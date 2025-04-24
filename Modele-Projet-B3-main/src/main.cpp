#include "config.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"
#include "etatFinal.h"
#include "matrice.h"
#include "a-star.h"

// Définition des variables globales
int i = 0;
StateMachine machine = StateMachine();
Button bouton(PIN_BOUTON);
unsigned long tempsDebut = 0;
MFRC522 mfrc522(PIN_SS, PIN_RST);
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
  SPI.begin();
  mfrc522.PCD_Init();
  

  Serial.println("Démarrage de la machine d'état");
  
  // Configuration des broches
  pinMode(PIN_LED, OUTPUT);
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
  // Mettre à jour la machine d'état
  //machine.run();
  if (i ==0){
    Serial.println("Matrice non traitée :");
    for (int j = 0; j < 169; j++)
    {
        matriceNonDecode[j] = matriceNonDecodeChar[j] - '0';
    }
    for (size_t i = 0; i < 169; i++)
    {
      Serial.print(matriceNonDecode[i]);
    }
    Serial.println();
    
    int** matriceDecode = processMatrix(matriceNonDecode);
    Serial.println("Matrice traitée :");
    for (int j = 0; j < 13; j++) {
      for (int k = 0; k < 13; k++) {
        Serial.print(matriceDecode[j][k]);
        Serial.print(" ");
      }
      Serial.println();
    }
    Serial.println("Listes des noeuds :");
    nodes = matrixToNodes(matriceDecode);
    for (int j = 0; j < 36; j++){
      Serial.print("Noeud ");
      Serial.print(j);
      Serial.print(" : ");
      Serial.print(nodes[j][0]);
      Serial.print(" ");
      Serial.print(nodes[j][1]);
      Serial.print(" ");
      Serial.print(nodes[j][2]);
      Serial.print(" ");
      Serial.print(nodes[j][3]);
      Serial.print(" ");
      Serial.print(nodes[j][4]);
      Serial.print(" ");
      Serial.print(nodes[j][5]);
      Serial.print(" ");
      Serial.println(nodes[j][6]);
    }
    free(nodes); // Libérer la mémoire allouée
    free(matriceDecode); // Libérer la mémoire allouée
    i++;
  }
  
  // Petit délai pour éviter une utilisation excessive du CPU
  delay(DELAI_BOUCLE_MS);
}
