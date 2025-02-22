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
    // {1} mit generate
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

























