#include <vector>
#include <algorithm>
#include <cctype>

#include "../funcs.h"

using namespace funcs;
using IntVector = std::vector<int>;

int main() {
    IntVector numbers = { 2, 4, -6, 8, 10};

    bool allEven = std::all_of(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    print("all even?", allEven);

    bool allPositive = std::all_of(numbers.begin(), numbers.end(), [](int n) { return n > 0; });
    print("all positive?", allPositive);

    std::string text = "Hello";

    bool allLower = std::all_of(text.begin(), text.end(), [](char c) { return std::islower(c); });
    print("all lower?", allLower);

}