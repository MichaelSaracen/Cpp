#include <algorithm>
#include <vector>

#include "../funcs.h"

using namespace funcs;
using IntVector = std::vector<int>;
using StringVector = std::vector<std::string>;


struct Person {
    std::string name;
    int age;
};

int main() {
    IntVector numbers = { 1, 3, 5, 7, 9};
    int targetNumber = 3;
    bool foundNumber = std::binary_search(numbers.begin(), numbers.end(), targetNumber,
        [](int a, int b) { return a < b; });
    print("foundNumber?", foundNumber ? "Zahl gefunden" : "Zahl nicht gefunden", "=", targetNumber);

    std::vector<Person> people = {
        {"Alice", 35},
        {"Bob", 30},
        {"Charlie", 33}
    };

    std::sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
    return p1.age < p2.age;
});

    Person target{"", 30};

    bool found = std::binary_search(people.begin(), people.end(), target,
                                [](const Person& p1, const Person& p2) {
                                    return p1.age < p2.age;
                                });

    print("foundPerson?", found ? "Person mit dem Alter gefunden": "Person mit dem Alter wurde nicht gefunden");

}
