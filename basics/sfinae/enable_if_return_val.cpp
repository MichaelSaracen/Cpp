#include <iostream>
#include <type_traits>
#include <windows.h>

template <typename ...Args>
void print(Args ...args) {
    SetConsoleOutputCP(CP_UTF8);
    ((std::cout << args << " "),  ...) << std::endl;
}

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, T> square(T x) {
    return x * x;
}

int main() {
    print("Beispiel mit Fließkommazahlen:", square(3.3));
    // print("Beispiel mit Ganzzahlen:", square(3)); Löst einen Compiler - Fehler aus.
    // [.cpp]:18:45: error: no matching function for call to 'square(int)'
}