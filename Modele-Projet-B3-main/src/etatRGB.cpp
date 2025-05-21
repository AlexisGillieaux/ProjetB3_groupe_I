#include "etatRGB.h"
#include "gestionRGB.h"

/**
 * @brief Gère l'état RGB en affichant la couleur actuelle.
 * 
 * Cette fonction appelle la fonction viewColor() pour afficher la couleur RGB sélectionnée.
 * 
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Cette fonction ne retourne aucune valeur.
 */
void EtatRGB() 
{
    viewColor();
}

/**
 * @brief Vérifie la condition de transition pour l'état RGB de la main droite.
 * 
 * @param Aucun paramètre d'entrée.
 * @return true si la condition de transition est remplie, false sinon.
 */
bool transition_RGB_MainDroite() 
{
    // À compléter : condition de transition

}
/**
 * @brief Vérifie si la transition vers l'état RGB Fauteuil doit être effectuée.
 * 
 * Cette fonction évalue si la composante bleue détectée dépasse un seuil prédéfini.
 * 
 * @param Aucun paramètre d'entrée explicite, utilise la variable globale colorDetecte.
 * @return true si la composante bleue (colorDetecte[2]) est supérieure à 140.0, false sinon.
 */
bool transition_RGB_Fauteuil() {
    // À compléter : condition de transition
    if(colorDetecte[2] > 140.0)
    {
        return true;
    }
    return false;
}
/**
 * @brief Vérifie si la transition de l'état RGB vers l'état Porte doit être effectuée.
 *
 * Cette fonction évalue une condition basée sur la détection de couleur pour déterminer
 * si la transition doit avoir lieu.
 *
 * @param Aucun paramètre d'entrée.
 * @return true si la valeur détectée pour la couleur rouge dépasse 140.0, false sinon.
 */
bool transition_RGB_Porte() {
    // À compléter : condition de transition
    if(colorDetecte[0] > 140.0)
     {
    
        return true;
    }
    return false;
}
/**
 * @brief Vérifie si la transition vers l'état final RGB doit être effectuée.
 * 
 * Cette fonction évalue si la condition de transition est remplie en fonction de la valeur détectée dans le tableau colorDetecte.
 * 
 * @param colorDetecte Tableau contenant les valeurs détectées pour chaque composante de couleur (doit être accessible dans la portée de la fonction).
 * @return true si la valeur de la composante verte (index 1) dépasse 100.0, false sinon.
 */
bool transition_RGB_Final() {
    // À compléter : condition de transition
   if(colorDetecte[1] > 100.0)
   {
        return true;
    }
    return false;
}
/**
 * @brief Vérifie si la transition RGB pour la main droite sur le fauteuil est possible.
 * 
 * Cette fonction détermine si la condition pour effectuer la transition RGB de la main droite sur le fauteuil est remplie.
 * 
 * @param Aucun paramètre d'entrée.
 * @return true si la transition est possible, false sinon.
 */
bool transition_RGB_MainDroiteFauteuil() {
    return true;
}