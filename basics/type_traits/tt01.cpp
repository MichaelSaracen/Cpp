/*
 * Datentyp und Instanzen - Check
 */

#include <iostream>
#include <type_traits>


struct A { };
struct B : public A { };
struct C {};

/**
 * Funktion zur Überprüfung von Datentypen, ob diese gleich sind. Liefert einen Wahrheitswert zurück
 * @tparam T
 * @tparam U
 * @param arg1
 * @param arg2
 * @return
 */
template <typename T, typename U>
bool isSame(const T& arg1, const U& arg2) { return std::is_same_v<T, U>; }

/**
 * Überladung: Funktion zur Überprüfung von Datentypen, ob diese gleich sind. Liefert einen Wahrheitswert zurück
 * @tparam T
 * @tparam U
 * @return
 */
template <typename T, typename U>
bool isSame() { return std::is_same_v<T, U>; }

/**
 * Funktion zur Überprüfung von Instanzen, ob diese gleich sind. Liefert einen Wahrheitswert zurück
 * @tparam Base
 * @tparam Derived
 * @param base
 * @param derived
 * @return
 */
template <typename Base, typename Derived>
bool isInstanceOf(const Base& base, const Derived& derived) { return std::is_base_of_v<Base, Derived>; }

/**
 * Überladung: Funktion zur Überprüfung von Instanzen, ob diese gleich sind. Liefert einen Wahrheitswert zurück
 * @tparam Base
 * @tparam Derived
 * @return
 */
template <typename Base, typename Derived>
bool isInstanceOf() { return std::is_base_of_v<Base, Derived>; }


/**
 * Funktion zur Ausgabe von mehreren Argumenten.
 * boolalpha gibt false oder true, anstatt Zahlen (0 oder 1) aus.
 * @tparam Args
 * @param args
 */
template<typename ...Args>
void print(Args&&... args) {
    std::cout << std::boolalpha;
    ((std::cout << args << " "), ...) << std::endl;
}

int main ( ) {
    int v1 = 10;
    double v2 = 20.3;
    int v3 = 5;
    A a1;
    A a2;
    B b1;
    C c1;

    print("Datentyp: v1 == v2 ?", isSame(v1, v2));
    print("Datentyp: v1 == v3 ?", isSame(v1, v3));
    print("Datentyp: a1 == a2 ?", isSame(a1, a2));
    print("Datentyp: a1 == b1 ?", isSame(a1, b1));
    print("Datentyp: float == double ?", isSame<float, double>());

    print("Instanz: a1 == a2", isInstanceOf(a1, a2));
    print("Instanz: a1 == b1", isInstanceOf(a1, b1));
    print("Instanz: b1 == c1", isInstanceOf(b1, c1));
    print("Instanz; A == C", isInstanceOf<A, C>());
}

/* Ausgabe:
    Datentyp: v1 == v2 ? false
    Datentyp: v1 == v3 ? true
    Datentyp: a1 == a2 ? true
    Datentyp: a1 == b1 ? false
    Datentyp: float == double ? false
    Instanz: a1 == a2 true
    Instanz: a1 == b1 true
    Instanz: b1 == c1 false
    Instanz; A == C false
*/
