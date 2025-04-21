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
MFRC522 mfrc522(PIN_SS, PIN_RST);
UltraSonicDistanceSensor ultrasonicSensor1(PIN_TRIGGER_1, PIN_ECHO_1);
UltraSonicDistanceSensor ultrasonicSensor2(PIN_TRIGGER_2, PIN_ECHO_2);
UltraSonicDistanceSensor ultrasonicSensor3(PIN_TRIGGER_3, PIN_ECHO_3);
UltraSonicDistanceSensor ultrasonicSensor4(PIN_TRIGGER_4, PIN_ECHO_4);


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
  machine.run();
}

void loop() {
  // Mettre à jour la machine d'état
  machine.run();
  
  // Petit délai pour éviter une utilisation excessive du CPU
  delay(DELAI_BOUCLE_MS);
}
