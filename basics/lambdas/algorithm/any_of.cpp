#include <vector>
#include <algorithm>
#include <cctype>
#include <array>

#include "../funcs.h"

using namespace funcs;
using IntVector = std::vector<int>;
using IntArray = std::array<int, 5>;

int main() {
    IntVector numbers = { 1,3,5,7, 8};
    bool hasEven = std::any_of(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    print("has even?", hasEven ? "es gibt mindestens eine gerade Zahl" : "es gibt keine gerade Zahlen");

    IntArray values = { 3, 6, -1 ,4, 12};
    bool hasNegative = std::any_of(values.begin(), values.end(), [](int n) { return n < 0; });
    print("has negative?", hasNegative ? "Mindestens eine Zahl ist negativ": "Keine Zahl ist negativ");

    std::string text = "Hello, World";
    bool hasSpecialChar = std::any_of(text.begin(), text.end(), [](char c) { return !std::isalnum(c) && !std::isspace(c); });
    print("has special char?", hasSpecialChar ? "Es gibt mindestens ein Sonderzeichen" : "Es gibt keine Sonderzeichen");

}