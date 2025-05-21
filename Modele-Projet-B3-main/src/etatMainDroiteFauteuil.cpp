#include "etatMainDroiteFauteuil.h"
#include "config.h"
#include "gestionMoteur.h"
#include "gestionUltrason.h"
#include "pid_controller.h"
#include "gestionRGB.h"
#include "mainDroite.h"

/**
 * @brief Gère l'état de la main droite lorsqu'elle interagit avec le fauteuil.
 *
 * Cette fonction appelle la logique associée à la fonctionnalité de la main droite
 * dans le contexte du fauteuil.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Cette fonction ne retourne aucune valeur.
 */
void EtatMainDroiteFauteuil()
 {

   mainDroiteFonctionnel();

}

/**
 * @brief Vérifie si la couleur détectée par la main droite sur le fauteuil dépasse un seuil spécifique.
 *
 * Cette fonction appelle viewColor() pour mettre à jour la détection de couleur, puis vérifie si la composante rouge (indice 2 de colorDetecte)
 * est supérieure à 140.0. Si c'est le cas, la transition est considérée comme valide.
 *
 * @param Aucun paramètre d'entrée.
 * @return true si la composante rouge détectée est supérieure à 140.0, false sinon.
 */
bool transition_MainDroiteFauteuil_Fauteuil() 
{ viewColor();
    if(colorDetecte[2]>140.0)
    { 
        return true;
    }

    return false;
}

