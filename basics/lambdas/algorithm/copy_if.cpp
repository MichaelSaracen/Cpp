#include "../funcs.h"

using namespace funcs;
using std::copy_if, std::string, std::back_inserter, std::sort;



int main() {
    PersonVector people = {
        {"Alice", 37}, {"Bob", 53}, {"Charlie", 25}, {"Tony", 22}, {"Eve", 40}
    };
    PersonVector olderThanThirty;

    copy_if(people.begin(), people.end(), back_inserter(olderThanThirty),
        [](const Person& p) { return p.age > 30; });

    sort(olderThanThirty.begin(), olderThanThirty.end(),
        [](const Person& p1, const Person& p2){ return p1.age < p2.age; });

    print("olderThanThirty =",olderThanThirty);


    IntVector numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    IntVector evenNumbers;

    copy_if(numbers.begin(), numbers.end(), back_inserter(evenNumbers),
        [](int n) { return n % 2 == 0; });

    print("evenNumbers =", evenNumbers);

    StringVector words = {"Haus", "Elefant", "Auto", "Computer", "Tisch", "Stuhl"};
    StringVector longWords;

    copy_if(words.begin(), words.end(), back_inserter(longWords),
        [](const string& word) { return word.length() > 5; });

    print("longWords =", longWords);
}

/* Ausgabe
    olderThanThirty = vector{Person{name=Alice, age=37},Person{name=Eve, age=40},Person{name=Bob, age=53}}
    evenNumbers = vector{2,4,6,8,10}
    longWords = vector{Elefant,Computer}
 */