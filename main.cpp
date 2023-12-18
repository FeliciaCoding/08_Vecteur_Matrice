#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <random>

const std::string MATRICE_TITLE      = "matrice";
const std::string SQUARE_TITLE       = "isSquare";
const std::string REGULAR_TITLE      = "isRegular";
const std::string LINE_MIN_TITLE     = "lineSizeMin";
const std::string LINE_MAN_TITLE     = "lineSizeMax";
const std::string VECT_LINE_TITLE    = "vectSumLine";
const std::string VECT_COL_TITLE     = "vectSumColumn";
const std::string VECT_MIN_TITLE     = "vectorSumMin";
const std::string SHUFFLE_MRIX_TITLE = "shuffleMatrix";
const std::string SORT_MRIX_TITLE    = "sortMatrix";


template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) { //operator<<	Affiche un vecteur au format
    os << "[";
    for_each(v.begin(), v.end() - 1, [&os](const T &i) { os << i << ','; });
    os << v[v.size() - 1];
    return os << "]";
}


template<typename T>
std::ostream &
operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) { //operator<<	Affiche un matrix au format
    os << "[";
    for_each(v.begin(), v.end() - 1, [&os](std::vector<T> i) { os << i << ','; });
    os << v[v.size() - 1];
    return os << "]";
}


template<typename T>
void printMatrix(const std::string &message, std::vector<std::vector<T>> &matrice) {
    std::cout << std::left << std::setw(15) << message << ": "
              << matrice << std::endl;

}

void printBool(const std::string &message, bool value) {
    std::cout << std::left << std::setw(15) << message << ": "
              << (value ? "yes" : "no") << std::endl;
}

template<typename T>
void printVector(const std::string &message, std::vector<T> &matrice) {
    std::cout << std::left << std::setw(15) << message << ": "
              << matrice << std::endl;

}


template<typename T>
bool isSquare(const std::vector<std::vector<T>> &matrice) {

    if (matrice.empty()) {
        return false;
    }

    size_t numCol = matrice[0].size();
    return std::all_of(matrice.begin(), matrice.end(), [numCol](const auto &row) {
        return row.size() == numCol;
    });

}


template<typename T>
std::vector<T> vectorSumMin(const std::vector<std::vector<T>> &matrice) {
    if (matrice.empty()) {
        return {};
    }

    auto minSumIterator = std::min_element(matrice.begin(), matrice.end(), [](const auto &row1, const auto &row2) {
        return (std::accumulate(row1.begin(), row1.end(), static_cast<T>(0))) <
               (std::accumulate(row2.begin(), row2.end(), static_cast<T>(0)));
    });

    if (minSumIterator != matrice.end()) {
        return *minSumIterator;
    } else {
        return {};
    }

}

template<typename T>
void shuffleVector(std::vector<T> &v) {
    // Reference: https://cplusplus.com/reference/algorithm/shuffle/?kw=shuffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(v.begin(), v.end(), std::default_random_engine(seed));

}


template<typename T>
void shuffleRow(std::vector<T> &row) {
    shuffleVector(row);
}

template<typename T>
void shuffleMatrix(std::vector<std::vector<T>> &matrice) {
    for_each(matrice.begin(), matrice.end(), shuffleRow<T>);;
    printMatrix(SHUFFLE_MRIX_TITLE, matrice);
}

template<typename T>
bool compareMin(const std::vector<T> &v1, const std::vector<T> &v2) {
    auto min1 = *min_element(v1.begin(), v1.end());
    auto min2 = *min_element(v2.begin(), v2.end());
    return min1 < min2;
}

template<typename T>
void sortMatrix(std::vector<std::vector<T>> &matrice) { // par valeur ou par référence ??
    sort(matrice.begin(), matrice.end(), compareMin<T>);
    printMatrix(SORT_MRIX_TITLE, matrice);
}


using namespace std;

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
    printBool(SQUARE_TITLE, isSquare(matrice));

    // isRegular      : no


    // lineSizeMin    : 1
    //// TODO : done by Paul, waiting for merging

    // lineSizeMax    : 3
    //// TODO : done by Paul, waiting for merging

    // vectSumLine    : [15, 16, 1]
    //// TODO : done by Cédric, waiting for merging

    // vectSumColumn  : [10, 5, 17]


    // vectorSumMin   : [1]
    VectorInt vSumMin = vectorSumMin(matrice);
    printVector(VECT_MIN_TITLE, vSumMin);

    // shuffleMatrix  : [[1], [4, 3, 9], [5, 2, 8]]	// exemple
    shuffleMatrix(matrice);

    // sortMatrix     : [[1], [5, 2, 8], [4, 3, 9]]
    sortMatrix(matrice);


    return EXIT_SUCCESS;
}
