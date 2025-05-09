#include "gestionRGB.h"
#include <string.h> // Pour utiliser strcpy


// Constructeur par défaut
void connexion() 
{
  //Serial.begin(115200);
  Serial.println("Color View Test!");

  while(!tcs.begin())
  {
    Serial.println("No TCS34725 found ... check your connections");
    delay(1000);
  }
}

void viewColor() {
  uint16_t clear, red, green, blue;
  tcs.getRGBC(&red, &green, &blue, &clear);
  // turn off LED
  tcs.lock();  
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
  Serial.println("\t");
  
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  Serial.print("\t");
  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  Serial.println();
  
}