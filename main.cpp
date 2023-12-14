#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <random>

using namespace std;

const string MATRICE_TITLE      = "matrice";
const string SQUARE_TITLE       = "isSquare";
const string REGULAR_TITLE      = "isRegular";
const string LINE_MIN_TITLE     = "lineSizeMin";
const string LINE_MAN_TITLE     = "lineSizeMax";
const string VECT_LINE_TITLE    = "vectSumLine";
const string VECT_COL_TITLE     = "vectSumColumn";
const string VECT_MIN_TITLE     = "vectorSumMin";
const string SHUFFLE_MRIX_TITLE = "shuffleMatrix";
const string SORT_MRIX_TITLE    = "sortMatrix";


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
    os << v[v.size() - 1];
    return os << "]";
}

template<typename T>
void printMatrix(const string &message, vector<vector<T>> &matrice) {
    cout << left << setw(15) << message << ": "
         << matrice << endl;

}


template<typename T>
void shuffleVector(vector<T> &v) {

    // Reference: https://cplusplus.com/reference/algorithm/shuffle/?kw=shuffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(v.begin(), v.end(), default_random_engine(seed));

}


template<typename T>
void shuffleRow(vector<T> &row) {
    shuffleVector(row);
}


template<typename T>

void shuffleMatrix(vector<vector<T>> &matrice) {

    for_each(matrice.begin(), matrice.end(), shuffleRow<T>);;

    printMatrix(SHUFFLE_MRIX_TITLE, matrice);

}


int main() {



    // matrice        : [[5, 2, 8], [4, 3, 9], [1]]
    using VectorInt = vector<int>;
    using Matrix = vector<VectorInt>;

    const VectorInt V1 = {5, 2, 8};
    const VectorInt V2 = {4, 3, 9};
    const VectorInt V3 = {1};

    Matrix matrice = {V1, V2, V3};

    printMatrix(MATRICE_TITLE, matrice);


    // isSquare       : no


    // isRegular      : no


    // lineSizeMin    : 1


    // lineSizeMax    : 3


    // vectSumLine    : [15, 16, 1]


    // vectSumColumn  : [10, 5, 17]


    // vectorSumMin   : [1]


    // shuffleMatrix  : [[1], [4, 3, 9], [5, 2, 8]]	// exemple

    shuffleMatrix(matrice);

    // sortMatrix     : [[1], [5, 2, 8], [4, 3, 9]]



    return EXIT_SUCCESS;
}
