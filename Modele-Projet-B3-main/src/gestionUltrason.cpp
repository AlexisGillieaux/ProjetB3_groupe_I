#include "gestionUltrason.h"


// Constructeur

/**
 * @brief Détecte la présence d'un obstacle à l'aide du capteur ultrason 1.
 *
 * Mesure la distance à l'aide du capteur ultrasonique et détermine si un obstacle est présent
 * à moins de 12 cm du capteur.
 *
 * @param Aucun paramètre d'entrée.
 * @return true si un obstacle est détecté à moins de 12 cm, false sinon.
 */
bool detecterObstacle1()
{
    // Mesurer la distance avec le capteur ultrason 1
    double distance1 = ultrasonicSensor1.measureDistanceCm();
    Serial.print("Distance 1: ");
    Serial.println(distance1);
    if (distance1 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
        return true;
    } else {
        return false;
    }
}
/**
 * @brief Mesure la distance à l'aide du capteur ultrason 1.
 *
 * Cette fonction utilise le capteur ultrasonique numéro 1 pour mesurer la distance
 * en centimètres et retourne la valeur mesurée.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return double La distance mesurée en centimètres.
 */
double getDistance1()
{
    // Mesurer la distance avec le capteur ultrason 1
    double distance1 = ultrasonicSensor1.measureDistanceCm();
    // Serial.print("Distance 1: ");
    // Serial.println(distance1);
    return distance1;
}
/**
 * @brief Détecte la présence d'un obstacle à l'aide du capteur ultrason numéro 2.
 *
 * Cette fonction mesure la distance détectée par le capteur ultrason 2 et
 * détermine si un obstacle est présent à moins de 12 cm.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return true si un obstacle est détecté à moins de 12 cm, false sinon.
 */
bool detecterObstacle2()
{
    // Mesurer la distance avec le capteur ultrason 2
    double distance2 = ultrasonicSensor2.measureDistanceCm();
    // Serial.print("Distance 2: ");
    // Serial.println(distance2);
    if (distance2 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
        return true;
    } else {
        return false;
    }
}
/**
 * @brief Mesure la distance à l'aide du capteur ultrason 2.
 *
 * Cette fonction utilise le capteur ultrason numéro 2 pour mesurer la distance en centimètres.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return double La distance mesurée en centimètres.
 */
double getDistance2()
{
    // Mesurer la distance avec le capteur ultrason 2
    double distance2 = ultrasonicSensor2.measureDistanceCm();
    // Serial.print("Distance 2: ");
    // Serial.println(distance2);
    return distance2;
}
/**
 * @brief Détecte la présence d'un obstacle à l'aide du capteur ultrason numéro 3.
 *
 * Cette fonction mesure la distance détectée par le capteur ultrason 3 et détermine
 * s'il y a un obstacle à moins de 12 cm du capteur.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return true si un obstacle est détecté à moins de 12 cm, false sinon.
 */
bool detecterObstacle3()
{
    // Mesurer la distance avec le capteur ultrason 3
    double distance3 = ultrasonicSensor3.measureDistanceCm();
    // Serial.print("Distance 3: ");
    // Serial.println(distance3);
    if (distance3 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
        return true;
    } else {
        return false;
    }
}
/**
 * @brief Mesure la distance à l'aide du capteur ultrason numéro 3.
 *
 * Cette fonction utilise le capteur ultrasonique 3 pour mesurer et retourner la distance détectée en centimètres.
 *
 * @param Aucun paramètre d'entrée.
 * @return double La distance mesurée par le capteur ultrason 3, en centimètres.
 */
double getDistance3()
{
    // Mesurer la distance avec le capteur ultrason 3
    double distance3 = ultrasonicSensor3.measureDistanceCm();
    // Serial.print("Distance 3: ");
    // Serial.println(distance3);
    return distance3;
}
/**
 * @brief Détecte la présence d'un obstacle à l'aide du capteur ultrason numéro 4.
 *
 * Cette fonction mesure la distance détectée par le capteur ultrason 4 et
 * détermine si un obstacle est présent à moins de 12 cm.
 *
 * @return true si un obstacle est détecté à moins de 12 cm, false sinon.
 */
bool detecterObstacle4()
{
    // Mesurer la distance avec le capteur ultrason 4
    double distance4 = ultrasonicSensor4.measureDistanceCm();
    Serial.print("Distance 4: ");
    Serial.println(distance4);
    if (distance4 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
        return true;
    } else {
        return false;
    }
}
/**
 * @brief Mesure la distance à l'aide du capteur ultrason numéro 4.
 *
 * Cette fonction utilise le capteur ultrason 4 pour mesurer et retourner la distance détectée en centimètres.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return double La distance mesurée par le capteur ultrason 4, en centimètres.
 */
double getDistance4()
{
    // Mesurer la distance avec le capteur ultrason 4
    double distance4 = ultrasonicSensor4.measureDistanceCm();
    // Serial.print("Distance 4: ");
    // Serial.println(distance4);
    return distance4;
}
