#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &vector) {
    os << "vector{";
    for (int i = 0; i < vector.size(); i++) {
        os << vector[i] << (i < vector.size()-1 ? "," : "}");
    }
    return os;
}

template <typename ...Args>
void print(const Args &...args) {
    ((cout << args << " "), ...) << endl;
}

int main() {
    vector<int> v1(10);
    int value = 1;
    generate(v1.begin(), v1.end(), [&]() { return value++; });
    print("Vector mit std::generate", v1);

    iota(v1.begin(), v1.end(), 10);
    print("Vector mit std::iota", v1);

    transform(v1.begin(), v1.end(), v1.begin(), [&value](int v) { return v / 2; });
    print("Vector mit std::transform", v1);

    fill_n(v1.begin(), v1.size(), 0);
    print("Vector mit std::fill_n", v1);

    fill(v1.begin(), v1.end(), 1);
    print("Vector mit std::fill", v1);

    for_each(v1.begin(), v1.end(), [&](int &n)  { n = -1 ;});
    print("Vector mit std::for_each", v1);

    auto create_vector = [&value]() {
        vector v(10, 1);
        transform(v.begin(), v.end(), v.begin(), [&value](int) { return value--;});
        return v;
    };

    vector<int> v2 = create_vector();
    print("create_vector", v2);
}


/* Ausgabe:
    Vector mit std::generate vector{1,2,3,4,5,6,7,8,9,10}
    Vector mit std::iota vector{10,11,12,13,14,15,16,17,18,19}
    Vector mit std::transform vector{5,5,6,6,7,7,8,8,9,9}
    Vector mit std::fill_n vector{0,0,0,0,0,0,0,0,0,0}
    Vector mit std::fill vector{1,1,1,1,1,1,1,1,1,1}
    Vector mit std::for_each vector{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    create_vector vector{11,10,9,8,7,6,5,4,3,2}
 */






















