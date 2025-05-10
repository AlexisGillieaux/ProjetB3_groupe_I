#include "config.h"
#include "gestionIR.h"

void setupReceiveIR() {
    IrReceiver.begin(PIN_IR_RECV, DISABLE_LED_FEEDBACK);
    Serial.println(F("Réception infrafouge prête, protocole : "));
    printActiveIRProtocols(&Serial);
    Serial.println();
}
    
void printReceivedIR() {
    if (IrReceiver.decode()) {
        Serial.println();
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.resume();  // Enable receiving of the next value
    }
}
void setupSendIR() {
    IrSender.begin(18,PIN_IR_SEND, ENABLE_LED_FEEDBACK);
    Serial.println(F("Envoi infrarouge prêt"));
    Serial.println(F("Protocole : "));
    printActiveIRProtocols(&Serial);
    Serial.println();
}

void printSendIR() {
    Serial.println(F("Envoi d'une trame infrarouge"));
    IrSender.sendSony(0xa90, 18);
    delay(500);
    Serial.println(F("Trame infrarouge envoyée"));
}