#include <gestionIR.h>


// Fonction d'initialisation de la gestion IR
void setupIR() 
{
    Serial.begin(9600); // Initialiser la communication série
    IrReceiver.enableIRIn(); // Démarrer la réception IR
    Serial.println("Prêt à recevoir des signaux IR...");
}
// Fonction pour afficher le signal IR reçu
void printReceivedIR() 
{
    decode_results results; // Déclarer une variable pour stocker les résultats IR
    if (IrReceiver.decode(&results)) // Vérifier si un signal IR a été reçu
    {
        Serial.print("Code IR reçu : ");
        Serial.println(results.value, HEX); // Afficher le code IR en hexadécimal
        IrReceiver.resume(); // Préparer la réception du prochain signal IR
    }
}