#include "../funcs.h"

using namespace funcs;
using std::count_if, std::string;

int main() {
    IntVector numbers {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int evenCount = count_if(numbers.begin(), numbers.end(),
        [](int num) { return num % 2 == 0; });
    print("evenCount =", evenCount);


    StringVector words = {"Haus", "Baum", "Autobahn", "Tisch", "Ei"};
    int shortWords = count_if(words.begin(), words.end(),
        [](const string& word) { return word.length() <= 4; });
    print("shortWords =", shortWords);

    IntVector numbers2 = {-5, 3, -1, 7, -9, 4, -2};
    int negativeNumbers = count_if(numbers2.begin(), numbers2.end(),
        [](int num) { return num < 0; });
    print("negativeNumbers =", negativeNumbers);
}

/* Ausgabe:
    evenCount = 5
    shortWords = 3
    negativeNumbers = 4
 */