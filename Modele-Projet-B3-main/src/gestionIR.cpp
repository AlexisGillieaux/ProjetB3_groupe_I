#include "config.h"
#include "gestionIR.h"
#include <IRremote.h>
#include <string.h> // Pour utiliser strcpy

// Variables globales
uint32_t signalEndingWith0 = 0;
uint32_t signalEndingWith1 = 0; // Signal se terminant par 1
bool isSignalEndingWith0Valid = false;
bool isSignalEndingWith1Valid = false;
 
// Variables pour mesurer les temps
unsigned long lastSignalTime0 = 0; // Temps du dernier signal se terminant par 0
unsigned long lastSignalTime1 = 0; // Temps du dernier signal se terminant par 1
unsigned long timeBetween0And1 = 0; // Temps entre un signal se terminant par 0 et un signal se terminant par 1
unsigned long timeBetween1And0 = 0; // Temps entre un signal se terminant par 1 et un signal se terminant par 0
 
void setupIR() {
    IrReceiver.begin(PIN_IR_RECV, DISABLE_LED_FEEDBACK);
    Serial.begin(9600);
    Serial.println(F("Réception infrarouge prête, protocole : "));
    printActiveIRProtocols(&Serial);
    Serial.println();
}
 
void printReceivedIR() {
    if (IrReceiver.decode()) {
        unsigned long currentSignalTime = millis(); // Temps actuel
 
        Serial.println("Signal IR reçu !");
       
        // Vérifier si le signal contient exactement 32 bits
        if (IrReceiver.decodedIRData.numberOfBits != 32) {
            Serial.print("Signal ignoré : nombre de bits incorrect (");
            Serial.print(IrReceiver.decodedIRData.numberOfBits);
            Serial.println(" bits reçus, attendu : 32 bits)");
            IrReceiver.resume(); // Préparer pour le prochain signal
            return; // Sortir de la fonction
        }
 
        // Stocker la valeur IR reçue
        uint32_t receivedValue = IrReceiver.decodedIRData.decodedRawData;
 
        // Vérifier si le signal se termine par 0 ou 1
        if (receivedValue & 0x1) {
            // Signal se terminant par 1
            signalEndingWith1 = receivedValue;
            isSignalEndingWith1Valid = true;
            Serial.print("Signal se terminant par 1 stocké : 0x");
            Serial.println(signalEndingWith1, HEX);
 
            // Calculer le temps entre le dernier 0 et ce 1
            if (lastSignalTime0 != 0) {
                timeBetween0And1 = currentSignalTime - lastSignalTime0;
                Serial.print("Temps entre 0 et 1 : ");
                Serial.print(timeBetween0And1);
                Serial.println(" ms");
            }
 
            lastSignalTime1 = currentSignalTime; // Mettre à jour le temps du dernier signal se terminant par 1
        } else {
            // Signal se terminant par 0
            signalEndingWith0 = receivedValue;
            isSignalEndingWith0Valid = true;
            Serial.print("Signal se terminant par 0 stocké : 0x");
            Serial.println(signalEndingWith0, HEX);
 
            // Calculer le temps entre le dernier 1 et ce 0
            if (lastSignalTime1 != 0) {
                timeBetween1And0 = currentSignalTime - lastSignalTime1;
                Serial.print("Temps entre 1 et 0 : ");
                Serial.print(timeBetween1And0);
                Serial.println(" ms");
            }
 
            lastSignalTime0 = currentSignalTime; // Mettre à jour le temps du dernier signal se terminant par 0
        }
 
        // Réinitialiser le récepteur pour le prochain signal
        IrReceiver.resume();
    }
}// Déclarations externes des variables globales

 
#define IR_SEND_PIN 8
 
void setupIR_upload() {
    IrSender.begin(IR_SEND_PIN);
    Serial.println(F("Envoi infrarouge prêt, protocole : "));
    printActiveIRProtocols(&Serial);
    Serial.println();
}
 
void IR_upload() {
    // Réémettre le signal se terminant par 0
    if (isSignalEndingWith0Valid) {
        Serial.print(F("Réémission du signal se terminant par 0 : 0x"));
        Serial.println(signalEndingWith0, HEX);
        IrSender.sendNEC(signalEndingWith0, 32, 0); // Réémettre le signal
 
        delay(100); // Pause avant d'envoyer le prochain signal
    }
 
    // Réémettre le signal se terminant par 1
    if (isSignalEndingWith1Valid) {
        Serial.print(F("Réémission du signal se terminant par 1 : 0x"));
        Serial.println(signalEndingWith1, HEX);
        IrSender.sendNEC(signalEndingWith1, 32, 0); // Réémettre le signal
 
        delay(50); // Pause avant d'envoyer le prochain signal
    }
 
   
   
}





























// void setupIR_upload(){
//     IrSender.begin(PIN_IR_SEND);
//     Serial.println(F("Envoi infrarouge prêt, protocole : "));
//     printActiveIRProtocols(&Serial);
//     Serial.println();
// }

// void IR_upload(){
//     digitalWrite(13, HIGH);
//     delay(100);
//     //digitalWrite(13, LOW);
//     delay(100);
    
//     Serial.println(F("Envoi infrarouge"));
//     Serial.println(F("Envoi de la trame : 0xC837FF00"));
//         Serial.println(F("Envoi de la trame : 0xC837FF00"));
//         Serial.println(F("Envoi de la trame : 0xC837FF00"));
//         IrSender.sendNEC(0xCB34FF00, 32, 0);
//         //; // Attendre avant d'envoyer la prochaine trame
//        // 0xC837FF00*/
//         IrSender.sendNEC(0xCC33FE01, 32, 0);
//         delay(DELAI_ATTENTE);
        
//     }

    
//     void setupReceiveIR() 
//     {
    
//         IrReceiver.begin(PIN_IR_RECV, DISABLE_LED_FEEDBACK);
//         Serial.println(F("Réception infrafouge prête, protocole : "));
//         printActiveIRProtocols(&Serial);
//         Serial.println();
//     }
    
//     void printReceivedIR() 
//     {
//         //setupReceiveIR();
//         if(IrReceiver.decode()) {
           
        
//         Serial.println(F("En attente d'une trame infrarouge"));
//         Serial.println();
//         IrReceiver.enableIRIn();  // Start the receiver
//         Serial.println(F("Trame infrarouge reçue"));
//         IrReceiver.start();
//         IrReceiver.printIRResultShort(&Serial);
//         IrReceiver.resume();  // Enable receiving of the next value
//         Serial.println(F("Trame infrarouge reçue"));
//         }
//         else {
//             Serial.println(F("Aucune trame infrarouge reçue"));
//         }
//     }
