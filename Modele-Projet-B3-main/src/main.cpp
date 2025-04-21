#include "config.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"
#include "etatFinal.h"

// Définition des variables globales
StateMachine machine = StateMachine();
Button bouton(PIN_BOUTON);
unsigned long tempsDebut = 0;
IRsend irsend(PIN_IR_SEND);
IRrecv irrecv(PIN_IR_RECV);
decode_results results;
DFRobot_TCS34725 tcs(&Wire, ADDRESS_TCS34725, TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
L298NX2 moteur(PIN_AIN1, PIN_AIN2, PIN_BIN1, PIN_BIN2);




// Création des états
State* etatInitial = machine.addState(&EtatInitial);
State* etatAttente = machine.addState(&EtatAttente);
State* etatAction = machine.addState(&EtatAction);
State* etatFinal = machine.addState(&EtatFinal);

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);
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
  machine.run();
}

void loop() {
  // Mettre à jour la machine d'état
  machine.run();
  
  // Petit délai pour éviter une utilisation excessive du CPU
  delay(DELAI_BOUCLE_MS);
}
