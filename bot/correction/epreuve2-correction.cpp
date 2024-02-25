#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @author Kettei
 * @date 15/12/2023
 * @version 1.0
 * Une correction possible pour trouver le flag{} de l'etage 2 - epreuve du nain
*/

// definitions des longueurs des tableaux 
#define MAX_SOL1 14
#define MAX_SOL2 33
#define MAX_SOL3 11


void fromIntToChar(string& sol, int arr[], int arr_len);

int main() {
  // tableaux de l'epreuve
  int sol1[] = {84,104,64,116,95,118,118,97,115,95,51,97,53,121};
  int sol2[] = {53,117,49,112,43,67,95,104,116,105,119,95,116,105,95,100,49,100,95,85,111,89,95,51,112,48,104,95,73,95,100,110,64};
  int sol3[] = {121,69,112,70,68,95,105,73,83,104,112};
  // initialisation d'un string
  string sol;

  // resolution de la premiere section du flag
  fromIntToChar(sol,sol1,MAX_SOL1);
  sol += '-'; // separe la section 1 et 2 du flag par un '-'

  // resolution de la deuxieme section du flag
  reverse(sol2,sol2+MAX_SOL2); // inverse le tableau
  fromIntToChar(sol,sol2,MAX_SOL2);
  sol += '-'; // separe la section 2 et 3 du flag par un '-'

  // resolution de la troisieme section du flag
  sort(sol3,sol3+MAX_SOL3); // tri le tableau
  fromIntToChar(sol,sol3,MAX_SOL3);

  // affiche le flag
  cout << "flag{" << sol << "}" << endl;

  system("pause"); // Fonctionne uniquement pour Windows, 
                   // permet de mettre en pause le programme 
                   // lorsque c'est pas automatique | pas obligatoire
  return 0;
}


/**
 * @brief Ajoute a une chaine de caractere les elments d'un tableau d'entiers en les convertissants en caracteres
 * @param[In/Out] sol Une chaine de caractere auquel va etre ajoute les elements du tableau
 * @param[In] arr Un tableau contenant les valeurs qui vont etre convertis en caracteres
 * @param[In] maxi Un entier qui est la longueur du tableau
*/
void fromIntToChar(string& sol, int arr[], int arr_len) {
  for (unsigned int i=0;i<arr_len;++i) {
    sol += char(arr[i]);
  }
}
