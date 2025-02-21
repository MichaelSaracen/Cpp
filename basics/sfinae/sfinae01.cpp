#include <iostream>
#include <type_traits>
#include <locale>
#include <windows.h> // Für SetConsoleOutputCP -> Umlaute ausgeben

template <typename ...Args>
void print(Args ...args) {
    SetConsoleOutputCP(CP_UTF8);
    ((std::cout << args << " "), ...) << std::endl;
}

template <typename T>
typename std::enable_if<std::is_integral_v<T>, void>::type foo(T) {
    print("foo()", "wird für integrale Typen aufgerufen");
}

template <typename T>
typename std::enable_if<std::is_floating_point_v<T>> ::type foo(T) {
    print("foo()", "wird für dezimale Typen aufgerufen");
}

template <typename T>
std::enable_if_t<!std::is_floating_point_v<T> && !std::is_integral_v<T>, void> foo(T) {
    print("foo()", "wird für nicht integrale und nicht dezimale Typen aufgerufen");
}

int main() {

    foo(33);
    foo(44.99);
    foo("Hello World");

    return 0;
}

/* Ausgabe:
foo() wird für integrale Typen aufgerufen
foo() wird für dezimale Typen aufgerufen
foo() wird für nicht integrale und nicht dezimale Typen aufgerufen
 */