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
void loopGestionRFID() {
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
uint16_t read(uint8_t *uid, uint8_t size) {
    // Lire l'UID de la carte RFID
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        for (byte i = 0; i < size; i++) {
            uid[i] = mfrc522.uid.uidByte[i];
        }
        return mfrc522.uid.size;
    }
    return 0;
}
// Fonction pour obtenir l'UID de la carte RFID
// idee pour win
// ecrire une fausse matrice utilisable pour tromper les autres utilisateurs