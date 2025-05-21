#include "etatPorte.h"
#include "config.h"
#include "RFID.h"
#include "gestionRGB.h"
#include "gestionMoteur.h"

bool etatporte = false;
/**
 * @brief Gère l'état de la porte en avançant le robot pendant une seconde.
 *
 * Cette fonction configure les moteurs pour avancer à une vitesse prédéfinie,
 * puis arrête le robot après un délai de 1 seconde.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return void Cette fonction ne retourne aucune valeur.
 */

void EtatPorte() 
{
    setSpeed1(200);
    setSpeed2(200);
    Avancer();
    delay(1000);
    setSpeed1(0);
    setSpeed2(0);
    Avancer();
    etatporte = true; // Mettre à jour l'état de la porte

}
bool transition_Porte_Sequence() {
    // À compléter : condition de transition
    return false;
}
bool transition_Porte_MainDroiteFauteuil() {
    if(PIN_MAIN_DROITE== HIGH && etatporte == true)
    {
        return true;
    }
    {
        return true;
    }
    return false;
}