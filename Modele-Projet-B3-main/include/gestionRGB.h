#include <config.h>
#ifndef GESTIONRGB_H
#define GESTIONRGB_H

#include <stdint.h> // Pour les types uint16_t

void setUpRgb(); // Fonction pour établir la connexion avec le capteur de couleur
void runOnce(); // Fonction pour afficher la couleur détectée

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


#endif // GESTIONRGB_H