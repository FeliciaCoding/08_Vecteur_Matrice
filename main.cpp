#include <cstdlib>
#include "matrixVectorUtils.h"

using namespace std;

int main() {

    using VectorInt = vector<int>;
    using Matrix = vector<VectorInt>;

    const VectorInt V1 = {5, 2, 8};
    const VectorInt V2 = {4, 3, 9};
    const VectorInt V3 = {1};

    Matrix matrice = {V1, V2, V3};
    print(MATRICE_TITLE, matrice);


    printBool(SQUARE_TITLE, isSquare(matrice));


    printBool(REGULAR_TITLE, isRegular(matrice));


    auto sizeMin = lineSizeMin<int, vector<vector<int>>::iterator>(matrice);
    print(LINE_MIN_TITLE, sizeMin);


    auto sizeMax = lineSizeMax<int, vector<vector<int>>::iterator>(matrice);
    print(LINE_MAX_TITLE, sizeMax);


    auto vSumLine = vectSumLine(matrice);
    print(VECT_LINE_TITLE, vSumLine);


    auto vSumCol = vectSumColumn(matrice);
    print(VECT_COL_TITLE, vSumCol);


    auto vSumMin = vectorSumMin(matrice);
    print(VECT_MIN_TITLE, vSumMin);


    shuffleMatrix(matrice);


    sortMatrix(matrice);

    return EXIT_SUCCESS;
}
