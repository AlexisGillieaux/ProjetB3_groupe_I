#include <config.h>
#ifndef GESTIONRGB_H
#define GESTIONRGB_H

#include <stdint.h> // Pour les types uint16_t

extern float colorReel[3]; // Tableau pour stocker les valeurs RGB
extern float colorDetecte[3]; // Tableau pour stocker les valeurs RGB détectées
class GestionRGB {
public:
    // Constructeur par défaut
    GestionRGB();

    // Constructeur avec paramètres pour initialiser les valeurs RGB
    GestionRGB(int red, int green, int blue);

    // Méthode pour détecter et renvoyer la couleur détectée
    char* detectColor() const;

private:
    int redValue;
    int greenValue;
    int blueValue;
};
void connection(); // Fonction pour établir la connexion avec le capteur de couleur
void viewColor(); // Fonction pour afficher la couleur détectée

#endif // GESTIONRGB_H