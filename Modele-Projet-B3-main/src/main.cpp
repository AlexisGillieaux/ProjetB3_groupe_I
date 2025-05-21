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
#include "etatFauteuil.h"











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
int color = 0;




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
State* etatFauteuil = machine.addState(&EtatFauteuil);


int f=0;
void setup() 
{
  Serial.begin(9600);
  SetTunings(2, 0, 2); // Initialisation des paramètres PID
  connexion();
  rfid_init();

  // Transitions classiques
  etatInitial->addTransition(&transition_Initial_Decodage, etatDecodage);
  etatDecodage->addTransition(&transition_Decodage_Porte, etatPorte);
  //etatPorte->addTransition(&transition_Porte_Sequence, etatMainDroiteFauteuil);


  etatMainDroiteFauteuil->addTransition(&transition_MainDroiteFauteuil_Fauteuil, etatFauteuil);
  etatMainDroiteFinal->addTransition(&transition_MainDroiteFinal_Final, etatFinal);

  etatRGB->addTransition(&transition_RGB_MainDroite, etatMainDroiteFinal);
  etatRGB->addTransition(&transition_RGB_Fauteuil, etatFauteuil);
  etatRGB->addTransition(&transition_RGB_Porte, etatPorte);
  etatRGB->addTransition(&transition_RGB_Final, etatFinal);

  etatFinal->addTransition(&transition_Final_Initial, etatInitial);

  // Transitions vers MainDroiteFauteuil depuis chaque état
  etatInitial->addTransition(&transition_Initial_MainDroiteFauteuil, etatMainDroiteFauteuil);
  etatFinal->addTransition(&transition_Final_MainDroiteFauteuil, etatMainDroiteFauteuil);
  etatDecodage->addTransition(&transition_Decodage_MainDroiteFauteuil, etatMainDroiteFauteuil);
  // etatPorte->addTransition(&transition_Porte_MainDroiteFauteuil, etatMainDroiteFauteuil);
  etatFauteuil->addTransition(&transition_Fauteuil_MainDroiteFauteuil, etatMainDroiteFauteuil);
  etatRGB->addTransition(&transition_RGB_MainDroiteFauteuil, etatMainDroiteFauteuil);
  etatMainDroiteFinal->addTransition(&transition_MainDroiteFinal_MainDroiteFauteuil, etatMainDroiteFauteuil);

  // Démarrer la machine dans l'état initial
 

  delay(100);
}

void loop() 
{ 
  if(PIN_MAIN_DROITE== LOW)
  {
     machine.run();
  }
  


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

  if(colorDetecte[0]>140.0)
  { 
    setSpeed1(-200);
    setSpeed2(-200);
    Avancer();
    delay(700);
    setSpeed1(0);
    setSpeed2(-80);
    Avancer();
    delay(500);
  }
  else if(colorDetecte[1]>100.0 && color==1)
  {
    Serial.println("Color detected: green");
    setSpeed1(0);
    setSpeed2(0);
    Avancer();
    delay(5000);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(1000);
    digitalWrite(PIN_BUZZER, LOW);
    delay(1000);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(1000);
    digitalWrite(PIN_BUZZER, LOW);
    //encoieReceiv();
    color=0;
    //delay(9999);
  }
  else if(colorDetecte[2]>140.0 && color==0)
  {
    Serial.println("Color detected: blue");
    setSpeed1(0);
    setSpeed2(0);
    Avancer();
    delay(5000);
    digitalWrite(PIN_BUZZER, HIGH);
    delay(1000);
    digitalWrite(PIN_BUZZER, LOW);
    
    color=1;

  }
    if(ultrasonArriere<13 && ultrasonGauche<30)
  {
     //delay(200);
     setSpeed1(-100);
     setSpeed2(100);
     Avancer();
      delay(500);
      setSpeed1(-85);
    setSpeed2(-70);
    Avancer();
    delay(700);
     
  }
  else if (ultrasonGauche>40 )
  {
   
    //delay(200);
    if(ultrasonDroite>25)
    { 
      setSpeed1(100);
     setSpeed2(-100);
     Avancer();
     delay(750);
  }
  else{setSpeed1(100);
     setSpeed2(-100);
     Avancer();
     delay(500);}
   
    
    setSpeed1(-85);
    setSpeed2(-70);
    Avancer();
    delay(700);
    

  }
  else
  {
      AvancementRegule(ultrasonGauche, ultrasonDroite, ultrasonArriere, ultrasonDevant);
  }
}

