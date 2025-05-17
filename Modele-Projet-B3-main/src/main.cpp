#include "config.h"
#include "RFID.h"
/*#include "RGB.h"
#include "Buzzer.h"
#include "Fin_course.h"
#include "SuiveurLine.h"
#include "multiplexeur_Tof.h"
#include "Moteur.h"
#include "IR_emeteur.h"*/
bool i = true;


void setup() {
  Serial.begin(9600);

  // Initialisations si besoin
  // Serial.println(digitalRead(Srgb));
  // Serial.println(digitalRead(Srfid));
  rfid_init(); 
  // RGB_init();
  // Buzzer_init();
  //Fin_course_init();
  // LINE_init();
  // multiplexeur_Tof_init();
  // MOTEUR_init();
  //IR_emetteur_init();
  delay(100);
}

void loop() 
{
  // Serial.println("*********************************************************************************************************************");
  Serial.print(dataComplete);
  // Serial.println("*********************************************************************************************************************");

  
  // Serial.println();
  // Serial.println();
  // Serial.println();
  // Serial.println();
  // Serial.println();
  // Serial.println();
  // Serial.println();
  
  rfidddd();

  if(dataComplete && i){

    i = false;
    Serial.println("");
    Serial.println("");
    Serial.println(dataComplete);
    Serial.println("");
    Serial.println("");
    for (size_t i = 0; i < 169; i++)
    {
      Serial.print(pointdata[i]);
    }
    
    
    int** nodes = (int**)malloc(36*sizeof(int*));
    int** matriceDecode = processMatrix(pointdata);
    Serial.println("Matrice traitée :");
    for (int j = 0; j < 13; j++) {
      for (int k = 0; k < 13; k++) {
        Serial.print(matriceDecode[j][k]);
        Serial.print(" ");
      }
      Serial.println();
    }
    nodes = matrixToNodes(matriceDecode);
    int startNode[7] = {0, 0, 0, 0, 0, 0, 0}; // Initialiser avec des valeurs par défaut
    int goalNode[7] =  {0, 0, 0, 0, 0, 0, 0};  // Initialiser avec des valeurs par défaut
    for (int j = 0; j < 36; j++) {

      if (nodes[j][3] == 1) { // Noeud de départ

        startNode[0] = nodes[j][0];
        startNode[1] = nodes[j][1];
        startNode[2] = nodes[j][2];
        startNode[3] = nodes[j][3];
        startNode[4] = nodes[j][4];
        startNode[5] = nodes[j][5];
        startNode[6] = nodes[j][6];
      }
      if (nodes[j][3] == 2) { // Noeud d'arrivée

        goalNode[0] = nodes[j][0];
        goalNode[1] = nodes[j][1];
        goalNode[2] = nodes[j][2];
        goalNode[3] = nodes[j][3];
        goalNode[4] = nodes[j][4];
        goalNode[5] = nodes[j][5];
        goalNode[6] = nodes[j][6];
      }
    }
    for (int j = 0; j < 36; j++){
      Serial.print("Noeud ");
      Serial.print(nodes[j][0]);
      Serial.print(" : ");
      Serial.print(nodes[j][1]);
      Serial.print(" ");
      Serial.print(nodes[j][2]);
      Serial.print(" ");
      Serial.print(nodes[j][3]);
      Serial.print(" ");
      Serial.print(nodes[j][4]);
      Serial.print(" ");
      Serial.print(nodes[j][5]);
      Serial.print(" ");
      Serial.print(nodes[j][6]);
      Serial.print(" ");
      Serial.println(nodes[j][7]);
    }
    int* dijkstraph = dijkstra(nodes, startNode);
    Serial.println("Liste d'antecedants :");
    for (int j = 0; j < 36; j++) {
      
      Serial.print(dijkstraph[j]);
      Serial.print(" ");
    }
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    int* pathdijk = antecedant(dijkstraph,goalNode,startNode);
    for (int j = 0; j < 36; j++) {
      Serial.print(pathdijk[j]);
      Serial.print(" ");
    }
    free(nodes);
    free(matriceDecode);
    free(pathdijk);
    free(dijkstraph);
  } 

  
  
  

  // Autres fonctions à activer si nécessaire :
  // LINE();
  //Fin_course();
  //while(1);
    
  //bool flag = rfid1Block(8);

  
    //   Serial.println("OKOK");
    // for (int i = 0; i < 169; i++) {
    //     Serial.print("Octet[");
    //     Serial.print(i);
    //     Serial.print("] = ");
    //     Serial.println(data[i]);
    //   }
    

  // RGB();
  // MOTEUR();
  // multiplexeur_Tof();
  //IR_emetteur_envoyer_code();

}