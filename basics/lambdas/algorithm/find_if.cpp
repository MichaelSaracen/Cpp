#include "../funcs.h"
#include "windows.h"

using namespace funcs;
using std::find_if, std::string;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    IntVector vec = {1, 2, 3, 4, 5};
    auto it = find_if(vec.begin(), vec.end(), [](int x) { return x > 3; });
    print((it != vec.end() ? "Erstes Element größer als 3: " + std::to_string(*it) : "Kein Element gefunden" ));

    StringVector words = {"apple", "banana", "avocado", "grape"};
    auto wordIt = find_if(words.begin(), words.end(), [](const string& word) { return word[0] == 'A' || word[0] == 'a'; });
    print((wordIt != words.end() ? "Erstes Wort, das mit a|A beginnt: " + *wordIt : "Kein Wort gefunden"));


}