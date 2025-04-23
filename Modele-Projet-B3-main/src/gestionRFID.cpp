#include "gestionRFID.h"

// Fonction d'initialisation de la gestion RFID
void setupGestionRFID() {
    Serial.begin(9600);		// Initialiser la communication série avec le PC
    SPI.begin();			// Initialiser le bus SPI
    mfrc522.PCD_Init();		// Initialiser le lecteur MFRC522
    delay(200);				// Délai optionnel. Certains modules ont besoin de plus de temps après l'initialisation pour être prêts.
    mfrc522.PCD_DumpVersionToSerial();	// Afficher les détails du PCD - Détails du lecteur de carte MFRC522
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}
// Fonction de boucle de gestion RFID
void UIDduRFID() {
    // Réinitialiser la boucle si aucune nouvelle carte n'est présente sur le capteur/lecteur. Cela économise tout le processus lorsqu'il est inactif.
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    // Vérifier si une carte est présente
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    // Afficher les détails de la carte lue
    Serial.print(F("UID tag :"));
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();
}
uint16_t read(uint8_t *uid, uint8_t size) 
{
    // Lire l'UID de la carte RFID
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        for (byte i = 0; i < size; i++) {
            uid[i] = mfrc522.uid.uidByte[i];
        }
        return mfrc522.uid.size;
    }
    return 0;
}
// Fonction pour effacer l'interruption
void clearInt(MFRC522 mfrc522) {
    // Effacer l'interruption en lisant la carte
    mfrc522.PICC_ReadCardSerial();
    mfrc522.PICC_HaltA(); // Mettre la carte en veille
    mfrc522.PCD_StopCrypto1(); // Arrêter la cryptographie
}
// Fonction pour lire les données d'un bloc spécifique et les stocker dans un buffer
bool lireDonneesCarte(MFRC522 &mfrc522, byte blockAddr, byte *buffer, byte *bufferSize, byte bufferSizeMax = 18) {
    // Authentification avec la clé A pour accéder au bloc
    MFRC522::MIFARE_Key key;
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF; // Clé par défaut : FFFFFFFFFFFF
    }

    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, blockAddr, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Échec de l'authentification : "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }

    // Lecture des données du bloc
    status = mfrc522.MIFARE_Read(blockAddr, buffer, bufferSize);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Échec de la lecture : "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }

    // Affichage des données lues
    Serial.print(F("Données lues du bloc "));
    Serial.print(blockAddr);
    Serial.print(F(": "));
    for (byte i = 0; i < *bufferSize; i++) {
        Serial.print(buffer[i], HEX);
        Serial.print(F(" "));
        *RFID = buffer[i]; // Stocker l'UID dans la variable globale RFID
    }
    Serial.println();

    // Arrêter la cryptographie
    mfrc522.PCD_StopCrypto1();
    return true;
}
// Fonction pour obtenir l'UID de la carte RFID
// idee pour win
// ecrire une fausse matrice utilisable pour tromper les autres utilisateurs