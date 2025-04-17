// ce fichier de configuration rassemble au même endroit toutes les constantes

// ces lignes permettent d'éviter les inclusions multiples
#ifndef CONFIG_H
#define CONFIG_H 



#include <Arduino.h>
#include <StateMachine.h>
#include <Button.h>

// le mot clé #define permet de définir des constantes, les valeurs seront effectivement remplacées
// dans le code avant la compilation.
// C'est une bonne pratique de mettre les constantes en majuscules.

// Définition des broches
#define PIN_LED 13
#define PIN_BOUTON 2

// Définition des délais
#define DELAI_ATTENTE 3000  // 3 secondes
#define DELAI_ACTION 5000   // 5 secondes
#define DELAI_BOUCLE_MS 10 // 10 millisecondes par boucle

// Déclaration des variables globales (définies dans main.cpp)
extern StateMachine machine;
extern Button bouton;
extern unsigned long tempsDebut;

#endif
