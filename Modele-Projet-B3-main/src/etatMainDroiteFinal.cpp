#include "etatMainDroiteFinal.h"
#include "config.h"
#include "mainDroite.h"

/**
 * @brief Gère la logique de l'état final de la main droite.
 * 
 * Cette fonction exécute les actions nécessaires lorsque l'état "MainDroiteFinal" est atteint.
 * 
 * @param Aucun paramètre.
 * @return Aucun retour.
 */
void EtatMainDroiteFinal() 
{
    // À compléter : logique de l'état MainDroiteFinal
   mainDroiteFonctionnel();
}

/**
 * @brief Vérifie la condition de transition de l'état MainDroiteFinal vers l'état Final.
 * 
 * Cette fonction évalue si la couleur détectée par le capteur 1 dépasse un seuil prédéfini.
 * 
 * @param colorDetecte Tableau de valeurs représentant les couleurs détectées par différents capteurs.
 * @return true si la valeur détectée par le capteur 1 est supérieure à 100.0, false sinon.
 */
bool transition_MainDroiteFinal_Final() 
{
    // À compléter : condition de transition
    if(colorDetecte[1]>100.0)
    { 
        return true;
    }
    return false;
}
/**
 * @brief Vérifie la transition de l'état MainDroiteFinal vers MainDroiteFauteuil.
 * 
 * Cette fonction teste si la condition de transition est remplie en lisant l'état du capteur PIN_MAIN_DROITE.
 * 
 * @param PIN_MAIN_DROITE L'état du capteur de la main droite (HIGH ou LOW).
 * @return true si la transition doit avoir lieu (PIN_MAIN_DROITE == HIGH), false sinon.
 */
bool transition_MainDroiteFinal_MainDroiteFauteuil() 
{
    if(PIN_MAIN_DROITE== HIGH)
    {
        return true;
    }
}