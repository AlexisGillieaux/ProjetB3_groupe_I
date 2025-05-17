#include "MainDroite2.h"
#include "gestionUltrason.h"
#include "gestionMoteur.h"

int baseSpeed1 = 90; // Vitesse de base du moteur gauche
int baseSpeed2 = 103; // Vitesse de base du moteur droit
void setupMainDroite2() {
    Serial.begin(9600); // Initialiser la communication série
    setupMoteur(); // Configurer les moteurs
    setSpeed2(66); // Vitesse du moteur droit
    setSpeed1(52); // Vitesse du moteur gauche
}

void mainDroite2(){
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
        if(distanceDroite > 28)
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
    else if(distanceDroite > 28)
    {
        setSpeed1(0); // Arrêter le moteur droit
        setSpeed2(0); // Arrêter le moteur gauche
    }
    else if(distanceDroite <= 28)
    {
        setSpeed1(54); // Arrêter le moteur droit
        setSpeed2(66); // Arrêter le moteur gauche
    }
    else if (distanceDevant > 30){
        setSpeed2(66); // Arrêter le moteur droit
        setSpeed1(54); // Arrêter le moteur gauche
    }
    Avancer();
}
void regulerVitesse()
{
    double distanceDevant = getDistance1();
    double distanceGauche = getDistance2();
    double distanceDroite = getDistance3();

    if (distanceDevant < 30)
    {
        setSpeed2(0); // Arrêter le moteur droit
        setSpeed1(0); // Arrêter le moteur gauche
        Avancer();

    }
    else{
        setSpeed2(baseSpeed2); // Vitesse du moteur droit
        setSpeed1(baseSpeed1); // Vitesse du moteur gauch
        Avancer();
        if(distanceDroite <= 10)
        {
            setSpeed2(baseSpeed2+3); // Arrêter le moteur droit
            setSpeed1(baseSpeed1-3); // Arrêter le moteur gauche
            Avancer();
        }
        else if(distanceGauche <= 10)
        {
            setSpeed2(baseSpeed2-3); // Arrêter le moteur droit
            setSpeed1(baseSpeed1+3); // Arrêter le moteur gauche
            Avancer();
        }
        
        Avancer();
    }
}