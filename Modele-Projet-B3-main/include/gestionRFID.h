#include "config.h"


// declaration des constructeurs
void setupGestionRFID();
void UIDduRFID();
void readCard();
void clearInt(MFRC522 mfrc522);
bool lireDonneesCarte(MFRC522 &mfrc522, byte blockAddr, byte *buffer, byte *bufferSize);
void activateRec(MFRC522 mfrc522); 
uint16_t read(uint8_t *uid, uint8_t size);

