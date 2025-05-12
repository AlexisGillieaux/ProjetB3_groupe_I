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
void setupReceiveIR();
void setupSendIR();

// Fonctions pour envoyer et recevoir des données IR
void sendIRData(uint16_t address, uint8_t command, uint8_t repeats);
void receiveIRData();

#endif // GESTION_IR_H