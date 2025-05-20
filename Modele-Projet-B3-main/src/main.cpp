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
#include "etatPorte.h"










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




// Création des états
State* etatInitial = machine.addState(&EtatInitial);
State* etatAttente = machine.addState(&EtatAttente);
State* etatAction = machine.addState(&EtatAction);
State* etatFinal = machine.addState(&EtatFinal);
State* etatRGB = machine.addState(&EtatRGB);
State* etatDecodage = machine.addState(&EtatDecodage);
State* etatMainDroite2 = machine.addState(&EtatMainDroiteFinal);
State* etatMainDroiteFauteuil = machine.addState(&EtatMainDroiteFauteuil);
State* etatMainDroiteFinal = machine.addState(&EtatMainDroiteFinal);
State* etatPorte = machine.addState(&EtatPorte);


int f=0;
void setup() 
{
  // Initialisation de la communication série
  Serial.begin(9600);
  //setupMainDroite2(); // Configurer les moteurs
  SetTunings(2, 0, 2); // Initialisation des paramètres PID
  connexion();
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
  double ultrasonDroite = ultrasonicSensor4.measureDistanceCm();
  double ultrasonGauche = ultrasonicSensor1.measureDistanceCm();
  double ultrasonDevant = ultrasonicSensor2.measureDistanceCm();
  double ultrasonArriere = ultrasonicSensor3.measureDistanceCm();
  if(ultrasonDroite==-1)
  {
    ultrasonDroite = 1;
  }
  if(ultrasonGauche==-1)
  {
    ultrasonGauche = 1;
  }
  if(ultrasonDevant==-1)
  {
    ultrasonDevant = 1;
  }
  if(ultrasonArriere==-1)
  {
    ultrasonArriere = 1;
  }


   viewColor();
  // Serial.print(ultrasonGauche);

  if(colorDetecte[0]>140.0)
  { 
    setSpeed1(255);
    setSpeed2(255);
    Avancer();
    delay(1000);
    setSpeed1(0);
    setSpeed2(-80);
    Avancer();
    delay(500);
  }
  // if(colorDetecte[1]>100.0)
  // { 
  //   //RecepteurIR();
  // }
  // if(colorDetecte[2]>140.0)
  // {
  //   //EmmeteurIR();
  // }
  // if(ultrasonArriere<30)
  // {
  //   setSpeed1(0);
  //   setSpeed2(0);
  //   Avancer();
  //   delay(1000);
  // }
  // if(ultrasonArriere<20)
  // {
  //   digitalWrite(PIN_BUZZER, HIGH);
  //   delay(2000);
  //   digitalWrite(PIN_BUZZER, LOW);
  // }
  // cul-de-sac
  // else if ((ultrasonArriere<15 && ultrasonGauche<20 && ultrasonDroite<20)||(ultrasonArriere<20 && ultrasonGauche<10 && ultrasonDroite<30) || (ultrasonArriere<20 && ultrasonDroite<30 && ultrasonDroite<10))
  // {
  //  setSpeed1(0);
  //   setSpeed2(0);
  //   delay(1000);
  //   setSpeed1(-120);
  //   setSpeed2(120);
  //   Avancer();
  //   delay(1000);
  //   setSpeed1(-80);
  //   setSpeed2(-90);
  //   Avancer();
  //   delay(500);
  // }
    if(ultrasonArriere<15 && ultrasonGauche<30)
  {
     delay(350);
     setSpeed1(-100);
     setSpeed2(100);
     Avancer();
      delay(500);
      setSpeed1(-80);
    setSpeed2(-80);
    Avancer();
    delay(400);
     
  }
  else if (ultrasonGauche>40 )
  {
   
    delay(350);
    setSpeed1(100);
    setSpeed2(-100);
    Avancer();
    delay(500);
    setSpeed1(-80);
    setSpeed2(-80);
    Avancer();
    delay(400);
    

  }

  // obstacle devant/libre gauche et droite

  // obstacle gauche et devant
  // else if (ultrasonGauche>35 && ultrasonDroite<30.0 && ultrasonArriere>35.0)
  // {
  //   setSpeed1(-80);
  //   setSpeed2(90);
  //   delay(500);
  // }
  // obstacle droite et devant

  //obstacle gauche et devant

  else
  {
      AvancementRegule(ultrasonGauche, ultrasonDroite, ultrasonArriere, ultrasonDevant);
  }
}

