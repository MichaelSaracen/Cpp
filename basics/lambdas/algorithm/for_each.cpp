#include "../funcs.h"

using namespace funcs;
using std::for_each, std::for_each_n, std::string;

int main() {
    IntVector vec = {1, 2, 3, 4, 5};
    for_each(vec.begin(), vec.end(), [](int& x) { x = x * x; });
    print(vec);


    StringVector names = {"Alice", "Bob", "Charlie"};
    for_each_n(names.begin(), names.size(), [](const string &name) {
        print("Hallo", name, "\b!");
    });

    int sum = 0;
    for_each(vec.begin(), vec.end(), [&sum](int x) { sum += x; });
    print("Summe der Elemente:", sum);
}

/* Ausgabe
vector{1,4,9,16,25}

Hallo Alice!
Hallo Bob!
Hallo Charlie!

Summe der Elemente: 55
 */