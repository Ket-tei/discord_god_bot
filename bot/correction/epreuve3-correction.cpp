#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * @author Kettei
 * @date 14/12/2023
 * @version 1.0
 * Une correction possible pour trouver le flag{} de l'etage 0 - epreuve des pierres
*/

// longueur du tableau
#define STONE 150

// tableau
int stone_tab[STONE] = {270,1,527,260,439,644,200,394,110,67,398,84,499,652,210,612,306,65,18,34,165,322,521,407,361,312,470,45,522,593,308,39,94,642,150,340,667,275,548,456,604,253,544,440,668,433,52,106,510,226,543,116,391,638,441,51,135,239,512,41,169,300,643,377,498,181,271,194,618,582,15,251,386,264,655,293,302,473,179,578,74,503,252,91,70,464,637,158,190,444,363,202,313,48,112,10,606,529,427,633,634,209,47,31,334,465,356,79,304,626,139,315,476,588,595,102,326,231,399,103,489,87,131,424,21,247,35,156,330,587,531,557,654,666,162,381,417,395,216,331,459,93,327,88,345,262,605,276,541,540};


int main() {
  // initialise une pile | vient du Header <stack>
  stack<int> stone_stack;
  // tri le tableau 'stone_tab' | vient du Header <algorithm>
  sort(stone_tab,stone_tab+STONE);

  // ajoute a la pile l'element le plus grand (forcement le dernier car tableau trie)
  // puis met l'element a -1 dans le tableau pour qu'il ne puisse plus etre pris en compte
  // (tous des entier non signé)
  stone_stack.push(stone_tab[STONE-1]);
  stone_tab[STONE-1] = -1;

  // ajoute a la pile le 2eme plus grand element puis le premier plus grand element(tmp)
  // on le repete: longueur du tableau(STONE) - 2elements (premier et dernier qui sont
  // des exceptions) / 2 car on ajoute a chaque tour de boucle 2 elements
  for (unsigned int i=0;i<(STONE-1)/2;++i) {
    int tmp = *max_element(stone_tab,stone_tab+STONE);
    stone_tab[max_element(stone_tab,stone_tab+STONE)-stone_tab] = -1;
    stone_stack.push(*max_element(stone_tab,stone_tab+STONE));
    stone_tab[max_element(stone_tab,stone_tab+STONE)-stone_tab] = -1;
    stone_stack.push(tmp);
  }
  // ajoute le premiere element etant l'element le plus petit (tableau trie)
  // pas besoin de le mettre a -1 car l'algo est fini
  stone_stack.push(stone_tab[0]);

  //affiche le flag
  cout << "flag{";
  while (!stone_stack.empty()) {
    cout << stone_stack.top(); // Affiche le sommet
    stone_stack.pop(); // supprime le sommet
  }
  cout<<"}"<<endl;

  system("pause"); // Fonctionne uniquement pour Windows, 
                   // permet de mettre en pause le programme 
                   // lorsque c'est pas automatique |pas obligatoire
  return 0;
}