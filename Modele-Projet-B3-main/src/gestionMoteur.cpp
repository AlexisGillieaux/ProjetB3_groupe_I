#include  "config.h"
#include  "gestionMoteur.h"


void Avancer() 
{
    // Avancer à une vitesse de 300
    moteur.setSpeedA(urielBG1); // Vitesse du moteur avant
    moteur.setSpeedB(urielBG2); // Vitesse du moteur avant
    moteur.forwardA(); // Avancer
    moteur.forwardB(); // Avancer
    Serial.println("Avancer"); // Afficher "Avancer" dans le moniteur série
}
void Reculer() 
{
    // Reculer à une vitesse de 50
    moteur.setSpeedA(urielBG1); // Vitesse du moteur reculer
    moteur.backwardA(); // Reculer
    moteur.setSpeedB(urielBG2); // Vitesse du moteur reculer
    moteur.backwardB(); // Reculer
    Serial.println("Reculer"); // Afficher "Reculer" dans le moniteur série

}
void tournerGauche() 
{
    // Tourner à gauche à une vitesse de 300
    moteur.setSpeedA(urielBG1); // Vitesse du moteur avant
    moteur.forwardA(); // Tourner à gauche
    moteur.setSpeedB(urielBG2); // Vitesse du moteur avant
    moteur.backwardB(); // Tourner à gauche
    Serial.println("Tourner à gauche"); // Afficher "Tourner à gauche" dans le moniteur série
}
void tournerDroite() 
{
    // Tourner à droite à une vitesse de 300
    moteur.setSpeedA(urielBG1); // Vitesse du moteur avant
    moteur.backwardA();// Tourner à droite
    moteur.setSpeedB(urielBG2); // Vitesse du moteur avant
    moteur.forwardB(); // Tourner à droite
    Serial.println("Tourner à droite"); // Afficher "Tourner à droite" dans le moniteur série
}

void Arreter() 
{
    // Arrêter le moteur
    moteur.stop(); // Arrêter le moteur
    Serial.println("Arrêter"); // Afficher "Arrêter" dans le moniteur série
}