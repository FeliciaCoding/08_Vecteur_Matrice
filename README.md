## Vecteurs et Matrices

### Objectif
- Utilisation de tableaux `vector<T>`
- Utilisation des `vector<T>::iterator`
- Utilisation intense de `algorithm` et `numeric` 🤔
- En conséquence, **aucune boucle explicite dans votre rendu !** 👍

<br>

### A faire
Développer une librairie générique mettant à disposition à minima les fonctionnalités listées

| Vocabulaire | Définition                                   | 
|-------------|----------------------------------------------| 
| vector      | tableau à 1 dimension `vector<T>`            |
| matrix      | tableau à 2 dimensions `vector< vector<T> >` | 

| Fonction      | Détail                                                                                                           |Notes | 
|:--------------|:-----------------------------------------------------------------------------------------------------------------|:----:| 
| operator<<    | Affiche un vecteur au format $[e_1, e_2, ..., e_n]$                                                              |  \*1 | 
| operator<<    | Affiche une matrice au format $[[v_1], [v_2], ..., [v_n]]$                                                       |  \*1 | 
| isSquare      | Retourne un booléen indiquant si la matrice est carrée                                                           |  \*2 | 
| isRegular     | Retourne un booléen indiquant si la matrice est régulière (nbre de lignes constant)                              |  \*2 | 
| lineSizeMin   | Retourne la longueur du plus petit vecteur d’une matrice                                                         |      | 
| lineSizeMax   | Retourne la longueur du plus grand vecteur d’une matrice                                                         |      | 
| vectSumLine   | Retourne un vecteur contenant la somme des valeurs de chacune des lignes                                         |      | 
| vectSumColumn | Retourne un vecteur contenant la somme des valeurs de chacune des colonnes                                       |  \*3 | 
| vectSumMin    | Retourne le vecteur d’une matrice dont la somme des valeurs est la plus faible                                   |      | 
| shuffleMatrix | Mélange les vecteurs d’une matrice sans altérer les vecteurs.<br>La `seed` du générateur est basée sur l’heure   |  \*4 | 
| sortMatrix    | Trie dans l’ordre choisi une matrice en fonction de l’élément `min` d’un vecteur                                 |      | 

|  No | Notes                                                                         |
|:---:|:------------------------------------------------------------------------------|
| \*1 | En utilisant des itérateurs et sans utiliser « auto »                         |
| \*2 | Une matrice vide est réputée être carrée et régulière                         |
| \*3 | Les éléments absents (*matrice irrégulière*) sont ignorés => `T()`            |
| \*4 | [shuffle](http://www.cplusplus.com/reference/algorithm/shuffle/?kw=shuffle)   |

<br>

<details>
<summary> Ce programme `main.cpp` produit le résultat ci-après </summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include "matrix.h"

using namespace std;

template <typename T>
using Vector = std::vector<T>;

template <typename T>
using Matrix = std::vector<Vector<T>>;

//------------------------------------------------------------------
int main(){

   Matrix<int> m = {{5, 2, 8}, {4, 3, 9}, {1}};

   cout << "matrice        : " << m                                  << endl;
   cout << "isSquare       : " << (isSquare<int>(m)  ? "yes" : "no") << endl;
   cout << "isRegular      : " << (isRegular<int>(m) ? "yes" : "no") << endl;
   cout << "lineSizeMin    : " << lineSizeMin<int>(m)                << endl;
   cout << "lineSizeMax    : " << lineSizeMax<int>(m)                << endl;
   cout << "vectSumLine    : " << vectSumLine<int>(m)                << endl;
   cout << "vectSumColumn  : " << vectSumColumn<int>(m)              << endl;
   cout << "vectorSumMin   : " << vectorSumMin<int>(m)               << endl;

   shuffleMatrix(m);
   cout << "shuffleMatrix  : " << m << endl;

   sortMatrix<int>(m, SortOrder::UP);
   cout << "sortMatrix     : " << m << endl;

   return EXIT_SUCCESS;
}
~~~

</details>

~~~
matrice        : [[5, 2, 8], [4, 3, 9], [1]]
isSquare       : no
isRegular      : no
lineSizeMin    : 1
lineSizeMax    : 3
vectSumLine    : [15, 16, 1]
vectSumColumn  : [10, 5, 17]
vectorSumMin   : [1]
shuffleMatrix  : [[1], [4, 3, 9], [5, 2, 8]]	// exemple
sortMatrix     : [[1], [5, 2, 8], [4, 3, 9]]
~~~

### Modalités
- exercices **mais à rendre**
- à faire **par groupe de 3 étudiants**
- 6 périodes

---
Bon travail
