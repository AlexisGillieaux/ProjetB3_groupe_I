#ifndef GESTION_IR_H
#define GESTION_IR_H
#include "config.h"

// Pour inclure la librarie IRremote, il faut faire un premier include dans le fichier main (voir main.cpp). 
// Ensuite, il faut inclure le fichier IRremoteInt.h avec la ligne suivante dans le code propre à l'infrarouge.
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE


#include <Arduino.h>
#include <IRremoteInt.h>




// void setupReceiveIR() ;
// void printReceivedIR() ;
// void setupSendIR() ;
// void printSendIR() ;


// Initialisation de l'émetteur et du récepteur IR
void setupIR();
void setupIR_upload();

// Fonctions pour envoyer et recevoir des données IR
void printReceivedIR();
void IR_upload();

#endif // GESTION_IR_H