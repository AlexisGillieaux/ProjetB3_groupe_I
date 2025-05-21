#include "config.h"
#include "gestionIR.h"
 
// Définition de la variable globale
storedIRDataStruct sStoredIRData0;
storedIRDataStruct sStoredIRData1;
 
/**
 * @brief Initializes the IR receiver and sender, and prints status messages to the serial monitor.
 * 
 * This function sets up the IR receiver on the specified pin with LED feedback enabled,
 * prints the supported IR protocols, initializes the IR sender, and outputs the send pin status.
 * 
 * @param None
 * @return void
 */
void setupIR() {
    IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
 
    IrSender.begin(); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin and enable feedback LED at default feedback LED pin
    Serial.print(IR_SEND_PIN);
    Serial.println(F(" is pressed."));
}
 
/**
 * @brief Stores the received IR code data if the address is 0.
 *
 * This function checks if the received IR data address is 0. If so, it stores the decoded IR data
 * or the raw IR data in the sStoredIRData0 structure, depending on whether the protocol is known or unknown.
 * It also prints a message to the Serial monitor indicating the type of data stored.
 *
 * @param None
 * @return void
 */
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
 
/**
 * @brief Handles the reception and processing of IR signals.
 *
 * This function checks if an IR signal has been received, prints the result to the serial monitor,
 * stores the received codes using storeCode0() and storeCode1(), and then resumes IR reception.
 *
 * @param None
 * @return void
 */
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
 
/**
 * @brief Envoie un code IR stocké, soit sous forme brute, soit sous forme décodée selon le protocole détecté.
 * 
 * Si le protocole du code IR reçu est inconnu, la fonction envoie les données brutes.
 * Sinon, elle envoie les données IR décodées (protocole, adresse, commande).
 * 
 * @param aIRDataToSend Pointeur vers la structure contenant les données IR à envoyer.
 * @return void Cette fonction ne retourne aucune valeur.
 */
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
/**
* @brief Envoie un code IR stocké, soit sous forme brute, soit sous forme décodée selon le protocole détecté.
* 
* Si le protocole du code IR reçu est inconnu, la fonction envoie les données brutes.
* Sinon, elle envoie les données IR décodées (protocole, adresse, commande).
* 
* @param aIRDataToSend Pointeur vers la structure contenant les données IR à envoyer.
* @return void Cette fonction ne retourne aucune valeur.
*/
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
/**
 * @brief Stores the received IR code data into the sStoredIRData1 structure if certain conditions are met.
 *
 * This function checks the validity of the received IR data, ignores repeat signals,
 * and only stores the data if the address is not 1. If the protocol is unknown, it stores
 * the raw code length and compensates/stores the raw IR result. Otherwise, it logs that
 * decoded IR data has been stored.
 *
 * @param None
 * @return void
 */
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

/**
 * @brief Vérifie, stocke et envoie les signaux infrarouges (IR) reçus si valides.
 *
 * Cette fonction appelle d'abord printReceivedIR() pour afficher les signaux IR reçus,
 * puis vérifie si les données IR stockées dans sStoredIRData0 et sStoredIRData1 sont valides
 * (c'est-à-dire que leur protocole n'est pas UNKNOWN). Si c'est le cas, elle envoie ces données
 * via les fonctions sendCode0 et sendCode1 respectivement, en ajoutant des délais pour éviter les collisions.
 *
 * @param Aucun paramètre.
 * @return Aucun retour.
 */
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
