#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>
#include <vector>

using namespace std;



template <typename T>
ostream& operator<< (ostream& os, vector<T> v) { //operator<<	Affiche un vecteur au format
    os << "[";
    for_each(v.begin(), v.end()-1,[&os](int i) { os << i << ','; });
    os<<v[v.size()-1];
    return os << "]";
}

template <typename T>
ostream& operator<< (ostream& os, vector<vector<T>> v) { //operator<<	Affiche un vecteur au format
    os << "[";

    for_each(v.begin(), v.end()-1,[&os](vector<T> i) { os << i << ','; } );
    os<<'[' <<v[v.size()-1]<<']';
    return os << "]";
}


int main() {

    vector v {1, 2, 3, 4, 5, 1, 2, 3, 4};
    cout<<v;

    vector<vector<int>> Matrix {{1,2,3},{8,7,6},{4,9,2},{1,4,5}};
    cout<<Matrix;
    return 0;
}
