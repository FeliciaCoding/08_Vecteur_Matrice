#include <iostream>
#include <ostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) { //operator<<	Affiche un vecteur au format
    os << "[";
    for_each(v.begin(), v.end() - 1, [&os](int i) { os << i << ','; });
    os << v[v.size() - 1];
    return os << "]";
}

template<typename T>
ostream &operator<<(ostream &os, vector<vector<T>> v) { //operator<<	Affiche un vecteur au format
    os << "[";

    for_each(v.begin(), v.end() - 1, [&os](vector<T> i) { os << i << ','; });
    os << '[' << v[v.size() - 1] << ']';
    return os << "]";
}

void print(int i) { cout << i << ' '; }

template<typename T, typename It>
size_t lineSizeMin(const vector<vector<T>> &vect) {
    if (vect.empty()) { return 0; }
    auto smallestVector = min_element(vect.begin(), vect.end(),
                                      [](const vector<int> &a, const vector<int> &b) { return a.size() < b.size(); });

    return smallestVector->size();
}

template<typename T, typename It>
size_t lineSizeMax(const vector<vector<T>> &vect) {
    if (vect.empty()) { return 0; }
    auto bigestVector = min_element(vect.begin(), vect.end(),
                                      [](const vector<int> &a, const vector<int> &b) { return a.size() > b.size(); });

    return bigestVector->size();
}

/*
size_t sortMatrix(){
    size_t result = 0;
    return result;
};

void lineSizeMax (){

}
*/



int main() {

    vector v{1, 2, 3, 4, 5, 1, 2, 3, 4};
    cout << v << endl;

    vector<vector<int>> Matrix{{1, 2, 3},
                               {8, 4, 5, 6, 4, 5, 6},
                               {4, 9, 2},
                               {1}};
    cout << Matrix << endl;

    cout << "lineSizeMin renvoie : " << lineSizeMin<int, vector<vector<int>>::iterator>(Matrix) << endl;
    cout << "lineSizeMax renvoie : " << lineSizeMax<int, vector<vector<int>>::iterator>(Matrix) << endl;

    /*using Ligne3 = array<double, 3>;
    Ligne3 maLigne{1,2,3};
    using Matrice3x3 = array<Ligne3, 3>;
    Matrice3x3 maMatrice{maLigne};
    for (Ligne3& ligne : matrice) {
        for (double element : ligne)
            cout << element << " => ";
        cout << endl;
    }

    // PRE
    // lineSizeMin    : 1
    // sortMatrix     : [[1], [5, 2, 8], [4, 3, 9]]
    // lineSizeMax    : 3
    // matrice        : [[5, 2, 8], [4, 3, 9], [1]]

    vector<int> line (4, 0);
    cout << "vector   : " << span<int>(line) << endl;

    vector<vector<int>> matrix4x3 (4, vector<int>(3, 0.));
    for (size_t i; i < matrix4x3[3].size(); ++i){
        cout << "matrix   : " << span<int>(line) << endl;
    }*/


    // isSquare       : no


    // isRegular      : no


    // vectSumLine    : [15, 16, 1]


    // vectSumColumn  : [10, 5, 17]


    // vectorSumMin   : [1]


    // shuffleMatrix  : [[1], [4, 3, 9], [5, 2, 8]]	// exemple

    return EXIT_SUCCESS;
}
