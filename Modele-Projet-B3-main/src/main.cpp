#include "config.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"
#include "etatFinal.h"

#include "gestionRGB.h"
#include <IRremote.hpp>
#include "IR.h"
#include "RFID.h"

#include <gestionIR.h>
#include "mainDroite.h"
#include "pid_controller.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"
#include "gestionRGB.h"
#include "MainDroite2.h"
#include "etatAction.h"
#include "etatDecodage.h"
#include "etatRGB.h"
#include "etatMainDroiteFauteuil.h"
#include "etatMainDroiteFinal.h"
#include "regulationPON.h"





// Définition des variables globales
bool i = true;
StateMachine machine = StateMachine();
Button bouton(PIN_BOUTON);
unsigned long tempsDebut = 0;
// MFRC522 mfrc522(PIN_SS, PIN_RST);
UltraSonicDistanceSensor ultrasonicSensor1(PIN_TRIGGER_1, PIN_ECHO_1);
UltraSonicDistanceSensor ultrasonicSensor2(PIN_TRIGGER_2, PIN_ECHO_2);
UltraSonicDistanceSensor ultrasonicSensor3(PIN_TRIGGER_3, PIN_ECHO_3);
UltraSonicDistanceSensor ultrasonicSensor4(PIN_TRIGGER_4, PIN_ECHO_4);
DFRobot_TCS34725 tcs(&Wire, ADDRESS_TCS34725, TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
L298NX2 moteur(PIN_AIN1, PIN_AIN2, PIN_BIN1, PIN_BIN2);
//int* matriceNonDecode = (int*)malloc(13 * 13 * sizeof(int)); 
//char matriceNonDecodeChar[] = "1111111111111112010041000111101011101011010100000101101011111110110100000000011011111111101100000001003110101111101311010100000121101110111110110000000000011111111111111";
//int** nodes = (int**)malloc(36*sizeof(int*));
int jklm = 0;
double commande=0;
bool changementDeMur=false;
bool first= true;



// Création des états
// State* etatInitial = machine.addState(&EtatInitial);
// State* etatAttente = machine.addState(&EtatAttente);
// State* etatAction = machine.addState(&EtatAction);
// State* etatFinal = machine.addState(&EtatFinal);
// State* etatRGB = machine.addState(&EtatRGB);
// State* etatDecodage = machine.addState(&EtatDecodage);
// State* etatMainDroite = machine.addState(&EtatMainDroiteFauteuil);
// State* etatMainDroite2 = machine.addState(&EtatMainDroiteFinal);

int f=0;
void setup() 
{
  // Initialisation de la communication série
  Serial.begin(9600);
  //setupMainDroite2(); // Configurer les moteurs
  // SetTunings(2, 0, 2); // Initialisation des paramètres PID
  //setupRegulationPON();
  
  //  SPI.begin();
  //mfrc522.PCD_Init();
  // connexion();
  rfid_init();
  //SetTunings(2, 0, 1); // Initialisation des paramètres PID
  // rfid_init();
  

  // Serial.println("Démarrage de la machine d'état");
  
  // Configuration des broches
  // pinMode(PIN_LED, OUTPUT);
  // setupIR_upload();
  // setupIR();
  //   setupIR_upload();
  // Configuration des transitions
  // etatInitial->addTransition(&transition_Initial_Attente, etatAttente);
  // etatAttente->addTransition(&transition_Attente_Action, etatAction);
  // etatAction->addTransition(&transition_Action_Final, etatFinal);
  // etatFinal->addTransition(&transition_Final_Initial, etatInitial);

  // Démarrer la machine dans l'état initial
  //machine.run();
  delay(100);

}

void loop() 
{ 
  
  // double ultrasonDroite = ultrasonicSensor4.measureDistanceCm();
  // double ultrasonGauche = ultrasonicSensor1.measureDistanceCm();
  // double ultrasonDevant = ultrasonicSensor2.measureDistanceCm();
  // double ultrasonArriere = ultrasonicSensor3.measureDistanceCm();
  // Serial.print("ultrason derrière : ");
  // Serial.println(ultrasonArriere);
  // if(first==true)
  // {   
  // setSpeed1(-120);
  //  setSpeed2(-120);
  //  Avancer();
  //   first=false;  
  //  delay(5000);
  // }
  rfidddd();

  // setSpeed1(-120);
  // setSpeed2(-120);
  // Avancer();
  // if(ultrasonArriere < 20 && ultrasonGauche < 20)
  // {
  //   setSpeed1(-120);
  //   setSpeed2(120);
  //   Avancer();
  //   delay(200);
  // }
  // else if(ultrasonArriere > 20 && ultrasonGauche > 20)
  // {
  //   setSpeed1(120);
  //   setSpeed2(-120);
  //   Avancer();
  //   delay(200);
    
  // }
  // else if(ultrasonArriere < 20 && ultrasonGauche > 20)
  // {
  //   setSpeed1(-120);
  //   setSpeed2(120);
  //   Avancer();
  //   delay(200);
    
  // }
  // else if(ultrasonArriere < 20 && ultrasonGauche > 20)
  // {
  //   setSpeed1(120);
  //   setSpeed2(-120);
  //   Avancer();
  //   delay(500);
    
  // }
  // Serial.print("ultrason Arrieere : ");
  // Serial.println(ultrasonArriere);
  if(ultrasonArriere<25.0  && ultrasonGauche<25.0)
  {
    // Arreter();
    // delay(2000);
     setSpeed1(-150);
     setSpeed2(100);
     Avancer();

  }
  else if(ultrasonArriere<25.0 && ultrasonDroite<25.0 )
  {// Arreter();
    // delay(2000);
     setSpeed1(100);
     setSpeed2(-150);
     Avancer();

  }
  // regulation correcte
else if (ultrasonGauche < 40)
{ 
commande = Compute(ultrasonGauche, 15.0);

  setSpeed1(-70- commande);
  setSpeed2(-70 + commande);
  
}
else if (ultrasonDroite < 40)
{
  commande = Compute(ultrasonDroite, 15.0);
  setSpeed1(-70 + commande);
  setSpeed2(-70 - commande);
  
}
else
{
  setSpeed1(-70);
  setSpeed2(-90);
  
  
}
Avancer();
}
  
