#include "gestionRFID.h"

 
 
/**
 * Fonction exécutée pendant l'état initial
 * éteint la LED et passe à l'état ATTENTE sur appui du bouton
 * @param aucun
 * @return code_matrice
 */
 
MFRC522 mfrc522(PIN_RFID_SS, PIN_RFID_RST);
// Clé par défaut (valeurs d’usine)
MFRC522::MIFARE_Key key;
 
void rfid_init() {
    SPI.begin(); // Initialisation du bus SPI
    mfrc522.PCD_Init(); //
    Serial.println("Scan PICC to see UID and type...");
 
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
      }
}
 
 
 
//Fonction de base
void rfidddd()
{
 
  // Attente d’une carte RFID
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;
  }
  // Récupération des informations de la carte RFID
  if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;
  }
  int labyrinthe[13][13];
 
 
  //   Read bloc 0 1 2
  //   write data
  bool flag = rfid1Block(4);
  flag = rfid1Block(5);
  flag = rfid1Block(6);
  flag = rfid1Block(8);
  flag = rfid1Block(9);
  flag = rfid1Block(10);
  flag = rfid1Block(12);
  flag = rfid1Block(13);
  flag = rfid1Block(14);
  flag = rfid1Block(16);
  flag = rfid1Block(17);
  // Affichage des informations de la carte RFID.
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
 
 
 
 
 
 
bool rfid1Block(byte block ) {
  int data[169];
 
  int j=0;
    byte buffer[18];
    byte size = 18;
    int secteur = block/4;
    byte firstBlock = secteur*4 +3;
    Serial.println(firstBlock);
    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
      MFRC522::PICC_CMD_MF_AUTH_KEY_A,
      firstBlock,
      &key,
      &(mfrc522.uid)
    );
    if (status != MFRC522::STATUS_OK) {
      Serial.print(F("PCD_Authenticate() failed: "));
      //Serial.println(GetStatusCodeName(status));
      return false;
    }
    // Read block
    byte byteCount = sizeof(buffer);
    status = mfrc522.MIFARE_Read(block, buffer, &size);
 
 
    // 📖 Lecture du bloc4
 
 
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Erreur lecture bloc ");
    Serial.print(block);
    Serial.print(" : ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    // mfrc522.PICC_HaltA();
    // mfrc522.PCD_StopCrypto1();
    return false;
  } else {
    Serial.print("Bloc ");
    Serial.print(block);
    Serial.println(" :");
    for (int i = 0; i < 16; i++) {
 
      Serial.print(buffer[i]);
      Serial.print(" ");
      if(j < 169)
      {
        data[j]=buffer[i];
        j++;
      }
    }
    Serial.println();
  }
 
 
 
 
  return false;
}
