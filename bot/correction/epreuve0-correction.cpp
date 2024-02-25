#include <iostream>
using namespace std;

/**
 * @author Kettei
 * @date 18/12/2023
 * @version 1.0
 * Une correction possible pour trouver le flag{} de l'etage 0 - epreuve du vieillard
*/

// definitions de la longueur du tableau 
#define MAX_PLANT 82


int main(){
  // tableaux de l'epreuve
  int plant[] = {0,69,0,112,0,0,0,0,114,0,101,0,117,0,118,0,101,45,0,49,48,0,48,32,45,62,0,32,102,108,97,103,123,0,0,95,89,48,85,95,0,64,82,51,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,78,0,79,86,86,0,95,0,65,0,0,0,95,71,48,0,68,0,95,125,0,0,0};

  // affiche le flag
  cout<<"flag{";
  for (unsigned int i=0; i<MAX_PLANT; ++i){
    if (plant[i]) cout << plant[i]; // si la plante n'est pas égale à 0 on l'affiche
  }
  cout << "}" << endl;

  system("pause"); // Fonctionne uniquement pour Windows, 
                   // permet de mettre en pause le programme 
                   // lorsque c'est pas automatique | pas obligatoire
  return 0;
}