#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;



template <typename T>
ostream& operator<< (ostream& os, vector<T> v) { //operator<<	Affiche un vecteur au format
    os << "[";
    for (size_t i=0; i<v.size(); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template <typename T>
ostream& operator<< (ostream& os, vector<vector<T>> v) { //operator<<	Affiche un vecteur au format
    os << "[";
    for (size_t i=0; i<v.size(); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}




int main() {

    vector v {1, 2, 3, 4, 5, 1, 2, 3, 4};
    cout<<v;


    return 0;
}
