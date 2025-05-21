#include "gestionRGB.h"
#include <string.h> // Pour utiliser strcpy


// Constructeur par défaut
/**
 * @brief Initialise la connexion avec le capteur de couleur TCS34725.
 *
 * Cette fonction initialise la communication série (commentée ici) et tente d'établir la connexion avec le capteur TCS34725.
 * Si le capteur n'est pas détecté, un message d'erreur est affiché et la tentative est répétée toutes les secondes.
 *
 * @param Aucun paramètre n'est requis pour cette fonction.
 * @return Cette fonction ne retourne aucune valeur.
 */
void connexion() 
{
  // Serial.begin(9600);
  Serial.println("Color View Test!");

  while(!tcs.begin())
  {
    Serial.println("No TCS34725 found ... check your connections");
    delay(1000);
  }
}

/**
 * @brief Reads RGB and clear values from the color sensor, normalizes the RGB values,
 *        and stores the detected color in the global colorDetecte array. Also prints
 *        the detected color values to the serial output.
 *
 * This function retrieves the red, green, blue, and clear channel values from the
 * TCS color sensor, normalizes the RGB values based on the clear channel, scales them
 * to the 0-255 range, and stores them in the colorDetecte array. The detected color
 * values are then printed to the serial monitor.
 *
 * @param None
 * @return void
 */
void viewColor() 
{
  uint16_t clear, red, green, blue;
  tcs.getRGBC(&red, &green, &blue, &clear);
  // turn off LED
  //tcs.lock();  
  // Serial.print("C:\t"); Serial.print(clear);
  // Serial.print("\tR:\t"); Serial.print(red);
  // Serial.print("\tG:\t"); Serial.print(green);
  // Serial.print("\tB:\t"); Serial.print(blue);
  // Serial.println("\t");
  
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  colorDetecte[0] = r;
  colorDetecte[1] = g;
  colorDetecte[2] = b;
  // Serial.print("\t");
  // Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  // Serial.println();
  Serial.print("Color detected: ");
  Serial.print((int)colorDetecte[0]);
  Serial.print(" ");
  Serial.print((int)colorDetecte[1]);
  Serial.print(" ");
  Serial.print((int)colorDetecte[2]);
  Serial.println();
  
}

// couleur des case

//rouge audessus de 140
// vert audessus de 100
// bleu audessus de 140