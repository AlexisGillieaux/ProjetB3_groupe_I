#include "gestionUltrason.h"


// Constructeur

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
double getDistance1()
{
    // Mesurer la distance avec le capteur ultrason 1
    double distance1 = ultrasonicSensor1.measureDistanceCm();
    Serial.print("Distance 1: ");
    Serial.println(distance1);
    return distance1;
}