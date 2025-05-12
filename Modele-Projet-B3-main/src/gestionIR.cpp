#include "config.h"
#include "gestionIR.h"

// void setupReceiveIR() {
//     IrReceiver.begin(PIN_IR_RECV, DISABLE_LED_FEEDBACK);
//     Serial.println(F("Réception infrafouge prête, protocole : "));
//     printActiveIRProtocols(&Serial);
//     Serial.println();
// }
    
// void printReceivedIR() {
//     setupReceiveIR();
//     Serial.println(F("En attente d'une trame infrarouge"));
//         Serial.println();
//         IrReceiver.enableIRIn();  // Start the receiver
//         Serial.println(F("Trame infrarouge reçue"));
//         IrReceiver.start();
//         IrReceiver.printIRResultShort(&Serial);
//         IrReceiver.resume();  // Enable receiving of the next value
//     Serial.println(F("Trame infrarouge reçue"));
// }
// void setupSendIR() {
//     IrSender.begin(18,PIN_IR_SEND, ENABLE_LED_FEEDBACK);
//     Serial.println(F("Envoi infrarouge prêt"));
//     Serial.println(F("Protocole : "));
//     printActiveIRProtocols(&Serial);
//     Serial.println();
// }

// void printSendIR() {
//     Serial.println(F("Envoi d'une trame infrarouge"));
//     IrSender.sendSony(0xa90, 18);
//     delay(500);
//     Serial.println(F("Trame infrarouge envoyée"));
// }
// struct storedIRDataStruct {
//     IRData receivedIRData;
//     // extensions for sendRaw
//     uint8_t rawCode[RAW_BUFFER_LENGTH]; // The durations if raw
//     uint8_t rawCodeLength; // The length of the code
// } sStoredIRData;
// void storeCode();
// void sendCode(storedIRDataStruct *aIRDataToSend);
#include <IRremote.h>

// Initialisation des objets pour l'émetteur et le récepteur IR

















































































































































// Émetteur IR

// Fonction pour initialiser le récepteur IR
void setupReceiveIR() {
    IrReceiver.begin(PIN_IR_RECV, DISABLE_LED_FEEDBACK); // Démarrer le récepteur IR
    Serial.println(F("Récepteur infrarouge prêt."));
}

// Fonction pour initialiser l'émetteur IR
// void setupSendIR() {
//     IrSender.begin(PIN_IR_SEND, ENABLE_LED_FEEDBACK); // Démarrer l'émetteur IR
//     Serial.println(F("Émetteur infrarouge prêt."));
// }

// Fonction pour envoyer des données IR
void sendIRData(uint16_t address, uint8_t command, uint8_t repeats) {
    Serial.print(F("Envoi des données IR : Adresse=0x"));
    Serial.print(address, HEX);
    Serial.print(F(", Commande=0x"));
    Serial.print(command, HEX);
    Serial.print(F(", Répétitions="));
    Serial.println(repeats);

    IrSender.sendNEC(address, command, repeats); // Envoi des données en utilisant le protocole NEC
    Serial.println(F("Données IR envoyées."));
}

// Fonction pour recevoir des données IR
void receiveIRData() {
    if (IrReceiver.decode()) { // Vérifier si des données IR ont été reçues
        Serial.print(F("Données IR reçues : Protocole="));
        Serial.print(getProtocolString(IrReceiver.decodedIRData.protocol));
        Serial.print(F(", Adresse=0x"));
        Serial.print(IrReceiver.decodedIRData.address, HEX);
        Serial.print(F(", Commande=0x"));
        Serial.println(IrReceiver.decodedIRData.command, HEX);

        IrReceiver.resume(); // Préparer la réception des prochaines données
    }
}