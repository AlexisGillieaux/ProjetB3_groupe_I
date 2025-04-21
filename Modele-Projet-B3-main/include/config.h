// ce fichier de configuration rassemble au même endroit toutes les constantes

// ces lignes permettent d'éviter les inclusions multiples
#ifndef CONFIG_H
#define CONFIG_H 



#include <Arduino.h>
#include <StateMachine.h>
#include <Button.h>
#include <IRremote.h>
#include <HCSR04.h>
#include <DFRobot_TCS34725.h>


// le mot clé #define permet de définir des constantes, les valeurs seront effectivement remplacées
// dans le code avant la compilation.
// C'est une bonne pratique de mettre les constantes en majuscules.

// Définition des broches
#define PIN_LED 13
#define PIN_BOUTON 2

// Définition des broches infrarouges
#define PIN_IR_SEND 32
#define PIN_IR_RECV 33

// Définition des broches ultrason
#define PIN_TRIGGER_1 34  // Pin for the trigger of the HC-SR04
#define PIN_ECHO_1 35    // Pin for the echo of the HC-SR04
#define PIN_TRIGGER_2 36  // Pin for the trigger of the second HC-SR04
#define PIN_ECHO_2 37    // Pin for the echo of the second HC-SR04
#define PIN_TRIGGER_3 38  // Pin for the trigger of the third HC-SR04
#define PIN_ECHO_3 39    // Pin for the echo of the third HC-SR04
#define PIN_TRIGGER_4 40  // Pin for the trigger of the fourth HC-SR04
#define PIN_ECHO_4 41    // Pin for the echo of the fourth HC-SR04

// Définition des broches du capteur de couleur
#define PIN_TCS_SDA 20    // Pin for the SDA of the TCS34725
#define PIN_TCS_SCL 21    // Pin for the SCL of the TCS34725


// Définition des délais
#define DELAI_ATTENTE 3000  // 3 secondes
#define DELAI_ACTION 5000   // 5 secondes
#define DELAI_BOUCLE_MS 10 // 10 millisecondes par boucle

// Déclaration des variables globales (définies dans main.cpp)
extern StateMachine machine;
extern Button bouton;
extern unsigned long tempsDebut;

#endif
