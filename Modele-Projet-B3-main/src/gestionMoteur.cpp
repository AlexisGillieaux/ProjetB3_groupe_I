#include  "config.h"
#include  "gestionMoteur.h"

double speed1 = 100;
double speed2 = 80;
/**
 * @brief Initialise les broches de contrôle du moteur en tant que sorties et les met à l'état bas.
 *
 * Cette fonction configure les broches AIN1, AIN2, BIN1 et BIN2 comme sorties pour le contrôle du moteur,
 * puis initialise leur valeur à 0 (état bas) pour s'assurer que le moteur est arrêté au démarrage.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Cette fonction ne retourne aucune valeur.
 */
void setupMoteur() 
{
    pinMode(PIN_AIN1, OUTPUT); // Configurer la broche AIN1 comme sortie
    pinMode(PIN_AIN2, OUTPUT); // Configurer la broche AIN2 comme sortie
    pinMode(PIN_BIN1, OUTPUT); // Configurer la broche BIN1 comme sortie
    pinMode(PIN_BIN2, OUTPUT); // Configurer la broche BIN2 comme sortie
    analogWrite(PIN_AIN1, 0); // Initialiser la broche AIN1 à 0
    analogWrite(PIN_AIN2, 0); // Initialiser la broche AIN2 à 0
    analogWrite(PIN_BIN1, 0); // Initialiser la broche BIN1 à 0
    analogWrite(PIN_BIN2, 0); // Initialiser la broche BIN2 à 0
}
/**
 * @brief Contrôle l'avance des moteurs en fonction des vitesses speed1 et speed2.
 *
 * Cette fonction ajuste la direction et la vitesse des moteurs en utilisant les broches de contrôle
 * et les valeurs de speed1 et speed2. Selon le signe de chaque vitesse, elle détermine le sens de rotation
 * de chaque moteur (avant ou arrière).
 *
 * @param speed1 Vitesse du moteur 1 (peut être positive ou négative pour indiquer le sens).
 * @param speed2 Vitesse du moteur 2 (peut être positive ou négative pour indiquer le sens).
 * @return void Cette fonction ne retourne aucune valeur.
 */
void Avancer() 
{   
    if(speed1 >= 0 && speed2 >= 0)
    {
        analogWrite(PIN_AIN2, speed2); 
        analogWrite(PIN_BIN2, 0);      
        analogWrite(PIN_BIN1, speed1); 
    }
    if (speed1 < 0 && speed2 < 0)
    {
        analogWrite(PIN_AIN1, -1*speed2); 
        analogWrite(PIN_AIN2, 0); 
        analogWrite(PIN_BIN2, -1*speed1);     
        analogWrite(PIN_BIN1, 0); 
    }
    if (speed1 >= 0  && speed2 < 0)
    {
        analogWrite(PIN_AIN1, -1*speed2); 
        analogWrite(PIN_AIN2, 0); 
        analogWrite(PIN_BIN2, 0);      
        analogWrite(PIN_BIN1, speed1); 
    }
    if(speed1 < 0 && speed2 >= 0)
    {
        analogWrite(PIN_AIN1, 0); 
        analogWrite(PIN_AIN2, speed2); 
        analogWrite(PIN_BIN2, -1*speed1);      
        analogWrite(PIN_BIN1, 0); 
    }
    

    // // Avancer à une vitesse de 300
    // moteur.setSpeedA(speed1); // Vitesse du moteur avant
    // moteur.setSpeedB(speed2); // Vitesse du moteur avant
    // moteur.forwardA(); // Avancer
    // moteur.forwardB(); // Avancer
    // Serial.println("Avancer"); // Afficher "Avancer" dans le moniteur série
}
/**
 * @brief Fait reculer le robot en contrôlant les moteurs via PWM.
 *
 * Cette fonction active les moteurs pour faire reculer le robot à une vitesse déterminée
 * par les variables globales speed1 et speed2. Les broches PIN_AIN1 et PIN_BIN2 sont activées
 * tandis que PIN_AIN2 et PIN_BIN1 sont désactivées pour obtenir le mouvement arrière.
 *
 * @param Aucun paramètre n'est requis, la fonction utilise les vitesses globales speed1 et speed2.
 * @return Cette fonction ne retourne aucune valeur.
 */
void Reculer() 
{
   
    analogWrite(PIN_AIN1, speed1); 
    analogWrite(PIN_AIN2, 0); 
    analogWrite(PIN_BIN2, speed2); 
    analogWrite(PIN_BIN1, 0); 

    // Reculer à une vitesse de 50
    // moteur.setSpeedA(speed1); // Vitesse du moteur reculer
    // moteur.backwardA(); // Reculer
    // moteur.setSpeedB(speed2); // Vitesse du moteur reculer
    // moteur.backwardB(); // Reculer
    // Serial.println("Reculer"); // Afficher "Reculer" dans le moniteur série

}
/**
 * @brief Fait tourner le robot vers la gauche en contrôlant la vitesse des moteurs.
 *
 * Cette fonction utilise les broches de contrôle des moteurs pour faire tourner le robot à gauche.
 * Les vitesses des moteurs sont déterminées par les variables globales `speed1` et `speed2`.
 *
 * @param Aucun paramètre n'est requis pour cette fonction. Les vitesses sont définies globalement.
 * @return void Cette fonction ne retourne aucune valeur.
 */
void tournerGauche() 
{
    analogWrite(PIN_AIN1, speed1); 
    analogWrite(PIN_AIN2, 0); 
    analogWrite(PIN_BIN1, speed2); 
    analogWrite(PIN_BIN2, 0); 
    // Tourner à gauche à une vitesse de 300
    // moteur.setSpeedA(speed1); // Vitesse du moteur avant
    // moteur.forwardA(); // Tourner à gauche
    // moteur.setSpeedB(speed2); // Vitesse du moteur avant
    // moteur.backwardB(); // Tourner à gauche
    // Serial.println("Tourner à gauche"); // Afficher "Tourner à gauche" dans le moniteur série
}
/**
 * @brief Fait tourner le robot vers la droite en contrôlant les moteurs.
 *
 * Cette fonction utilise les broches de contrôle des moteurs pour faire tourner le robot vers la droite
 * à une vitesse définie par la variable globale speed2.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return void Cette fonction ne retourne aucune valeur.
 */
void tournerDroite() 
{
    analogWrite(PIN_AIN1, 0); 
    analogWrite(PIN_AIN2, speed2); 
    analogWrite(PIN_BIN1, 0); 
    analogWrite(PIN_BIN2, speed2); 
    // Tourner à droite à une vitesse de 300
    // moteur.setSpeedA(speed1); // Vitesse du moteur avant
    // moteur.backwardA();// Tourner à droite
    // moteur.setSpeedB(speed2); // Vitesse du moteur avant
    // moteur.forwardB(); // Tourner à droite
    // Serial.println("Tourner à droite"); // Afficher "Tourner à droite" dans le moniteur série
}

/**
 * @brief Arrête tous les moteurs en mettant leur vitesse à zéro.
 *
 * Cette fonction met à zéro la vitesse de tous les moteurs connectés aux broches
 * PIN_AIN1, PIN_AIN2, PIN_BIN1 et PIN_BIN2, arrêtant ainsi le mouvement du système.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Cette fonction ne retourne aucune valeur.
 */
void Arreter() 
{
    analogWrite(PIN_AIN1, 0); 
    analogWrite(PIN_AIN2, 0); 
    analogWrite(PIN_BIN1, 0); 
    analogWrite(PIN_BIN2, 0); 
    // Arrêter le moteur
    // moteur.stop(); // Arrêter le moteur
    // Serial.println("Arrêter"); // Afficher "Arrêter" dans le moniteur série
}
// moteur gauche
/**
 * @brief Définit la vitesse du moteur gauche.
 * 
 * Cette fonction assigne la valeur passée en paramètre à la variable globale speed1.
 * 
 * @param speed La nouvelle vitesse à appliquer au moteur en marche arrière.
 * @return La vitesse du moteur après modification.
 */
double setSpeed1(double speed) 
{
   
    speed1 = speed; 
   
    return speed1;
}
//moteur droite
/**
 * @brief Définit la vitesse du moteur doit.
 * 
 * Cette fonction assigne la valeur passée en paramètre à la variable globale speed2.
 * 
 * @param speed La nouvelle vitesse à appliquer au moteur en marche arrière.
 * @return La vitesse du moteur après modification.
 */
double setSpeed2(double speed) 
{
  
    speed2 = speed; // Vitesse du moteur reculer

    return speed2;
}

