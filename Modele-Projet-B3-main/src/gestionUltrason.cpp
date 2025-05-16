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
// bool detecterObstacle2()
// {
//     // Mesurer la distance avec le capteur ultrason 2
//     double distance2 = ultrasonicSensor2.measureDistanceCm();
//     Serial.print("Distance 2: ");
//     Serial.println(distance2);
//     if (distance2 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
//         return true;
//     } else {
//         return false;
//     }
// }
// double getDistance2()
// {
//     // Mesurer la distance avec le capteur ultrason 2
//     double distance2 = ultrasonicSensor2.measureDistanceCm();
//     Serial.print("Distance 2: ");
//     Serial.println(distance2);
//     return distance2;
// }
// bool detecterObstacle3()
// {
//     // Mesurer la distance avec le capteur ultrason 3
//     double distance3 = ultrasonicSensor3.measureDistanceCm();
//     Serial.print("Distance 3: ");
//     Serial.println(distance3);
//     if (distance3 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
//         return true;
//     } else {
//         return false;
//     }
// }
// double getDistance3()
// {
//     // Mesurer la distance avec le capteur ultrason 3
//     double distance3 = ultrasonicSensor3.measureDistanceCm();
//     Serial.print("Distance 3: ");
//     Serial.println(distance3);
//     return distance3;
// }
// bool detecterObstacle4()
// {
//     // Mesurer la distance avec le capteur ultrason 4
//     double distance4 = ultrasonicSensor4.measureDistanceCm();
//     Serial.print("Distance 4: ");
//     Serial.println(distance4);
//     if (distance4 < 12) { // Si la distance est inférieure à 10 cm, un obstacle est détecté
//         return true;
//     } else {
//         return false;
//     }
// }
// double getDistance4()
// {
//     // Mesurer la distance avec le capteur ultrason 4
//     double distance4 = ultrasonicSensor4.measureDistanceCm();
//     Serial.print("Distance 4: ");
//     Serial.println(distance4);
//     return distance4;
// }
