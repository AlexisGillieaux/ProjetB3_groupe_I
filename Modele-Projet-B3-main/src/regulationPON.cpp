#include <config.h>
#include <gestionMoteur.h>
#include <PID_v1.h>

// Variables pour la régulation
double distanceMur = 0;      // Distance mesurée par le capteur (droite ou gauche)
double correction = 0;
double setpoint = 10;        // Distance cible par rapport au mur (ex: 10 cm du mur)
double dummyInput = 0;       // Variable factice pour PID_v1 (on n'utilise pas la vitesse ici)

// PID : on régule la distance au mur
PID pidMur(&distanceMur, &correction, &setpoint, 4, 0, 5, P_ON_M, DIRECT);

void setupRegulationPON() {
    setSpeed1(56);
    setSpeed2(70);
    distanceMur = 0;
    correction = 0;
    setpoint = 50; // On veut rester à 10 cm du mur
    pidMur.SetMode(AUTOMATIC);
}

void regulationPON(double distDroite, double distGauche) {
    // Choix du mur de référence : priorité au mur droit, sinon mur gauche
    bool murDroite = (distDroite < 40 ); // mur détecté à droite
    bool murGauche = (distGauche < 40 && distDroite > 0); // mur détecté à gauche

    if (murDroite) {
        distanceMur = distDroite;
    } else if (murGauche) {
        distanceMur = distGauche;
    } else {
        // Aucun mur détecté, avance tout droit
        setSpeed1(70);
        setSpeed2(70);
        return;
    }

    pidMur.Compute();

    // Applique la correction sur les moteurs
    double baseSpeed = 70;
    double newSpeedGauche, newSpeedDroite;

    if (murDroite) {
        // Si trop près du mur droit, ralentir moteur droit, accélérer gauche
        newSpeedGauche = baseSpeed - correction;
        newSpeedDroite = baseSpeed + correction;
    } else {
        // Si trop près du mur gauche, ralentir moteur gauche, accélérer droit
        newSpeedGauche = baseSpeed + correction;
        newSpeedDroite = baseSpeed - correction;
    }

    // Limite les vitesses pour éviter les valeurs hors plage
    if (newSpeedGauche < 50) newSpeedGauche = 50;
    if (newSpeedGauche > 100) newSpeedGauche = 100;
    if (newSpeedDroite < 60) newSpeedDroite = 60;
    if (newSpeedDroite > 100) newSpeedDroite = 100;

    setSpeed1(newSpeedDroite); // moteur gauche
    setSpeed2(newSpeedGauche); // moteur droit
}