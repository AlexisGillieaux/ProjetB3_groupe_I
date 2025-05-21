#include "etatInitial.h"
#include "config.h"
#include "RFID.h"
#include "gestionIR.h"
#include "gestionRGB.h"


void EtatSequence() {
  
  
//Resourdre les sequences de characters avec 0 = avancer, 1 = gauche, 2 = droite

}
 

bool transition_Sequence_Shortcut() {
  return dataComplete;
}

bool transition_Sequence_Fauteuil() {
    return true; 
}
bool transition_Sequence_Final() {
    return true; 
}
