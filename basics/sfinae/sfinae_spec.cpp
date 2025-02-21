#include <iostream>

template <typename T, typename Enable = void>
struct CheckType {
    static void print() { std::cout << "unbekannter Typ\n"; }
};

template <typename T>
struct CheckType<T, std::enable_if_t<std::is_integral_v<T>>> {
    static void print() { std::cout << "Ganzzahltyp\n"; }
};

template <typename T>
struct CheckType<T, std::enable_if_t<std::is_same_v<T, std::string>>> {
    static void print() { std::cout << "String-Typ\n"; }
};

int main() {
    CheckType<int>::print();
    CheckType<double>::print();
    CheckType<std::string>::print();
}

/* Ausgabe
    Ganzzahltyp
    unbekannter Typ
    String-Typ
 */