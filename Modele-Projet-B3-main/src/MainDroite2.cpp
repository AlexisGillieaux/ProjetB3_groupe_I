#include "MainDroite2.h"
#include "gestionUltrason.h"
#include "gestionMoteur.h"

int baseSpeed1 = 60;  // Vitesse de base du moteur gauche
int baseSpeed2 = 50; // Vitesse de base du moteur droit
void setupMainDroite2()
{
    Serial.begin(9600); // Initialiser la communication série
    setupMoteur();      // Configurer les moteurs
    setSpeed2(baseSpeed2);      // Vitesse du moteur droit
    setSpeed1(baseSpeed1);      // Vitesse du moteur gauche
}

void mainDroite2()
{
    double distanceDevant = getDistance1();
    double distanceGauche = getDistance2();
    double distanceDroite = getDistance3();
    // Serial.print("Distance devant: ");
    // Serial.println(distanceDevant);
    // Serial.print("Distance gauche: ");
    // Serial.println(distanceGauche);
    // Serial.print("     ");
    // Serial.print(distanceDevant);
    // Serial.print("     ");
    if (distanceDevant < 30)
    {
        setSpeed2(0); // Arrêter le moteur droit
        setSpeed1(0); // Arrêter le moteur gauche
        Avancer();
        delay(200);
        if (distanceDroite > 28)
        {
            setSpeed1(160); // Tourner à droite
            setSpeed2(-80); // Tourner à droite
            Avancer();
            delay(440);
        }
        else if (distanceDroite <= 28)
        {
            setSpeed1(-80); // Tourner à droite
            setSpeed2(160); // Tourner à droite
            Avancer();
            delay(440);
        }
    }
    else if (distanceDroite > 28)
    {
        setSpeed1(0); // Arrêter le moteur droit
        setSpeed2(0); // Arrêter le moteur gauche
    }
    else if (distanceDroite <= 28)
    {
        setSpeed1(54); // Arrêter le moteur droit
        setSpeed2(66); // Arrêter le moteur gauche
    }
    else if (distanceDevant > 30)
    {
        setSpeed2(66); // Arrêter le moteur droit
        setSpeed1(54); // Arrêter le moteur gauche
    }
    Avancer();
}
void regulerVitesse()
{
    static double lastDevant = 0;
    static double lastGauche = 0;
    static double lastDroite = 0;


    double distanceDevant = getDistance2();
    double distanceGauche = getDistance1();
    double distanceDroite = getDistance4();

    // Fonction pour vérifier le changement de 5%
    auto hasChanged = [](double last, double current) {
        if (last == 0) return true; // Toujours afficher la première fois
        double diff = abs(current - last);
        return (diff / last) > 0.10; // Changement de 5%
    };

    bool changeDevant = hasChanged(lastDevant, distanceDevant);
    bool changeGauche = hasChanged(lastGauche, distanceGauche);
    bool changeDroite = hasChanged(lastDroite, distanceDroite);

    if (changeDevant || changeGauche || changeDroite) {
        Serial.print("Distance devant: ");
        Serial.print(distanceDevant);
        Serial.print(" | gauche: ");
        Serial.print(distanceGauche);
        Serial.print(" | droite: ");
        Serial.println(distanceDroite);
        lastDevant = distanceDevant;
        lastGauche = distanceGauche;
        lastDroite = distanceDroite;
        Serial.print("Vitesse moteur gauche: ");
        Serial.print(speed1);
        Serial.print(" | Vitesse moteur droit: ");
        Serial.println(speed2);
    }

    if (distanceDevant < 30)
    {
        setSpeed2(0); // Arrêter le moteur droit
        setSpeed1(0); // Arrêter le moteur gauche
        Avancer();
    }
    else
    {
        setSpeed2(baseSpeed2); // Vitesse du moteur droit
        setSpeed1(baseSpeed1); // Vitesse du moteur gauche
        // Avancer();
        if (distanceDroite <= 12)
        {
            setSpeed2(baseSpeed2 + 30);
            setSpeed1(baseSpeed1 - 30);
            // Avancer();
        }
        else if (distanceGauche <= 12)
        {
            setSpeed2(baseSpeed2 - 30);
            setSpeed1(baseSpeed1 + 30);
            // Avancer();
        }
        Avancer();
    }
}