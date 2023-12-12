#include <iostream>
#include <cstdlib>
#include <vector>
#include <span>
#include <vector>

using namespace std;

size_t lineSizeMin(){
    size_t result = 0;
    return result;
};

size_t sortMatrix(){
    size_t result = 0;
    return result;
};

void lineSizeMax (){

}

template<typename T>
ostream &operator<<(ostream &os, span<T> s) {
    os << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        if (i) os << ", ";
        os << s[i];
    }
    return os << "]";
}

int main() {

    // matrice        : [[5, 2, 8], [4, 3, 9], [1]]
    vector< vector<int> > m;
    cout << m << endl;



    // isSquare       : no


    // isRegular      : no


    // vectSumLine    : [15, 16, 1]


    // vectSumColumn  : [10, 5, 17]


    // vectorSumMin   : [1]


    // shuffleMatrix  : [[1], [4, 3, 9], [5, 2, 8]]	// exemple

    // PRE
    // lineSizeMin    : 1
    // sortMatrix     : [[1], [5, 2, 8], [4, 3, 9]]
    // lineSizeMax    : 3



    return EXIT_SUCCESS;
}
