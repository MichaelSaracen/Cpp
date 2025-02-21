#include <iostream>
#include <type_traits>
#include <windows.h>


template <typename T>
void print(T n, std::enable_if_t<std::is_integral_v<T>>* = nullptr) {
    std::cout << "Ganzzahl: " << n << std::endl;
}

template <typename T>
void print(T n, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr) {
    std::cout << "Fließkommazahl: " << n << std::endl;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    print(10);
    print(11.1);
}

/* Ausgabe:
    Ganzzahl: 10
    Fließkommazahl: 11.1
 */