#include "config.h"
#include "gestionIR.h"
 
// Définition de la variable globale
storedIRDataStruct sStoredIRData0;
storedIRDataStruct sStoredIRData1;
 
void setupIR() {
    IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
 
    IrSender.begin(); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin and enable feedback LED at default feedback LED pin
    Serial.print(IR_SEND_PIN);
    Serial.println(F(" is pressed."));
}
 
void storeCode0() {
   
    // Vérifier si l'adresse est 0
    if (IrReceiver.decodedIRData.address != 0) {
        // Copie des données reçues dans la structure
        sStoredIRData0.receivedIRData = IrReceiver.decodedIRData;
        return;
    }
 
   
 
    if (sStoredIRData0.receivedIRData.protocol == UNKNOWN) {
        sStoredIRData0.rawCodeLength = IrReceiver.decodedIRData.rawDataPtr->rawlen - 1;
        IrReceiver.compensateAndStoreIRResultInArray(sStoredIRData0.rawCode);
        Serial.println(F("Données brutes stockées (adresse 0)."));
    } else {
        Serial.println(F("Données IR décodées et stockées (adresse 0)."));
    }
}
 
void printReceivedIR() {
    if (IrReceiver.decode()) {
        Serial.println();
        IrReceiver.printIRResultShort(&Serial);
 
        // Appeler la fonction pour stocker les données
        storeCode0();
        storeCode1();
 
        IrReceiver.resume();  // Enable receiving of the next value
    }
}
 
void sendCode0(storedIRDataStruct *aIRDataToSend) {
    if (aIRDataToSend->receivedIRData.protocol == UNKNOWN) {
        Serial.println(F("Envoi des données brutes :"));
        for (uint8_t i = 0; i < aIRDataToSend->rawCodeLength; i++) {
            Serial.print(aIRDataToSend->rawCode[i]);
            Serial.print(F(" "));
        }
        Serial.println();
        IrSender.sendRaw(aIRDataToSend->rawCode, aIRDataToSend->rawCodeLength, 38);
        Serial.println(F("Données brutes envoyées."));
    } else {
        Serial.println(F("Envoi des données IR décodées :"));
        Serial.print(F("Protocole : "));
        Serial.println(aIRDataToSend->receivedIRData.protocol);
        Serial.print(F("Adresse : "));
        Serial.println(aIRDataToSend->receivedIRData.address, HEX);
        Serial.print(F("Commande : "));
        Serial.println(aIRDataToSend->receivedIRData.command, HEX);
        IrSender.write(&aIRDataToSend->receivedIRData);
        Serial.println(F("Données IR envoyées."));
    }
}
 
void sendCode1(storedIRDataStruct *aIRDataToSend) {
    if (aIRDataToSend->receivedIRData.protocol == UNKNOWN) {
        Serial.println(F("Envoi des données brutes :"));
        for (uint8_t i = 0; i < aIRDataToSend->rawCodeLength; i++) {
            Serial.print(aIRDataToSend->rawCode[i]);
            Serial.print(F(" "));
        }
        Serial.println();
        IrSender.sendRaw(aIRDataToSend->rawCode, aIRDataToSend->rawCodeLength, 38);
        Serial.println(F("Données brutes envoyées."));
    } else {
        Serial.println(F("Envoi des données IR décodées :"));
        Serial.print(F("Protocole : "));
        Serial.println(aIRDataToSend->receivedIRData.protocol);
        Serial.print(F("Adresse : "));
        Serial.println(aIRDataToSend->receivedIRData.address, HEX);
        Serial.print(F("Commande : "));
        Serial.println(aIRDataToSend->receivedIRData.command, HEX);
        IrSender.write(&aIRDataToSend->receivedIRData);
        Serial.println(F("Données IR envoyées."));
    }
}
void storeCode1() {
    if (IrReceiver.decodedIRData.rawDataPtr->rawlen < 4) {
        return;
    }
 
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
        return;
    }
 
    // Vérifier si l'adresse est 1
    if (IrReceiver.decodedIRData.address != 1) {
         // Copie des données reçues dans la structure
        sStoredIRData1.receivedIRData = IrReceiver.decodedIRData;
        return;
    }
 
   
    if (sStoredIRData1.receivedIRData.protocol == UNKNOWN) {
        sStoredIRData1.rawCodeLength = IrReceiver.decodedIRData.rawDataPtr->rawlen - 1;
        IrReceiver.compensateAndStoreIRResultInArray(sStoredIRData1.rawCode);
        Serial.println(F("Données brutes stockées (adresse 1)."));
    } else {
        Serial.println(F("Données IR décodées et stockées (adresse 1)."));
    }
}

void encoieReceiv()
{
    // Vérifier et stocker les signaux reçus
    printReceivedIR();
   
    // Envoyer les données IR uniquement si elles sont valides
    if (sStoredIRData0.receivedIRData.protocol != UNKNOWN) {
        Serial.println(F("Envoi des données IR stockées..."));
        sendCode0(&sStoredIRData0);
    delay(100);
    }
   
    delay(500);
    if(sStoredIRData1.receivedIRData.protocol != UNKNOWN) {
        Serial.println(F("Envoi des données IR stockées..."));
        sendCode1(&sStoredIRData1);
    }
    delay(100);
   
   
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
