#include "config.h"
#include "RFID.h"
/*#include "RGB.h"
#include "Buzzer.h"
#include "Fin_course.h"
#include "SuiveurLine.h"
#include "multiplexeur_Tof.h"
#include "Moteur.h"
#include "IR_emeteur.h"*/
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
double vitesse1=0;
double vitesse2=0;
double distance1 = 0;
double distance2 = 0;







// Création des états
State* etatInitial = machine.addState(&EtatInitial);
State* etatAttente = machine.addState(&EtatAttente);
State* etatAction = machine.addState(&EtatAction);
State* etatFinal = machine.addState(&EtatFinal);
int f=0;
void setup() 
{
  // Initialisation de la communication série
  Serial.begin(9600);
    SetTunings(2, 0, 5); // Initialisation des paramètres PID
  //  SPI.begin();
  // mfrc522.PCD_Init();
  // connexion();
  // rfid_init();
  //SetTunings(2, 0, 1); // Initialisation des paramètres PID
  rfid_init();
  speed1 = 120;
  speed2 = 120;
  

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
  rfidddd();

//   distance1= ultrasonicSensor1.measureDistanceCm();
//   distance2= ultrasonicSensor2.measureDistanceCm();
//  vitesse2 = Compute(distance2,20);
//  vitesse1 = Compute(distance1,20);
//   Serial.print("vitesse1 : ");
//   Serial.println(vitesse1);
//   Serial.print("vitesse2 : ");
//   Serial.println(vitesse2);

//   if(vitesse1<=38)
//   {
//     Serial.print("speed1 : ");
//     Serial.print(speed1);
//     speed1 = 38;
//     Serial.print("et ");
//     Serial.print(speed1);

//   }
//   if(vitesse1>=100)
//   {
//     Serial.print("speed1 : ");
//     Serial.println(speed1);
//     speed1 = 60;
//      Serial.print("et ");
//     Serial.print(speed1);

//   }
//   if (vitesse2<=30)
//   {
//     Serial.print("speed2 : ");
//     Serial.println(speed2);
//     speed2 = 38;
//      Serial.print("et ");
//     Serial.println(speed2);
//   }
//   if(vitesse2>=100)
//   {
//     Serial.print("speed2 : ");
//     Serial.println(speed2);
//     speed2 = 68;
//      Serial.print("et ");
//     Serial.println(speed2);
//   }

//   setSpeed1(vitesse1);
//   setSpeed2(vitesse2);
//   Avancer();

//   speed1 = 110;
//   speed2 = 120;
//   setSpeed1(speed1);
//   setSpeed2(speed2);
//   Avancer();
//   delay(2000);
//  Arreter();
  // Avancer();
  //  delay(1000);
  //  Arreter(); 
  //  delay(5000);
  //mainDroite(ultrasonicSensor1.measureDistanceCm(), ultrasonicSensor2.measureDistanceCm(), ultrasonicSensor3.measureDistanceCm());
  // if(ultrasonicSensor1.measureDistanceCm() < 30)
  // {
  //   Serial.println("Obstacle détecté");
  //   Arreter();
  //   //delay(5000); // Tourner à gauche pendant 5 secondes
  // }
  // else
  // {
  //   Serial.println("Pas d'obstacle détecté");
  //   Avancer();
  // }
 
  // Compute(ultrasonicSensor2.measureDistanceCm(),speed1,10);
  // Compute(ultrasonicSensor3.measureDistanceCm(),speed2,10);
  
  // Serial.println(setSpeed1(speed1));
  // Serial.println(setSpeed2(speed2));
  // Avancer();
  //delay(3000);
  // Serial.println( ultrasonicSensor3.measureDistanceCm());
  // delay(3000);
  // tournerGauche();
  //delay(5000); // Tourner à gauche pendant 5 seconde

  
}
