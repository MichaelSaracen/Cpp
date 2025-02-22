#include <iostream>
#include <windows.h>  // SetConsoleOutputCP -> Umlaute etc
#include <utility> // exchange -> stehlen

template <typename ...Args>
void print(Args ...args) { ((std::cout << args << " "), ...) << std::endl; }

class Resource {
public:
    // Konstruktor
    Resource(int value): m_ptr(new int(value)) {
        print("Ressource für", *m_ptr , "erstellt");
    }

    // Destruktor (Punkt 1)
    ~Resource() {
        delete m_ptr;
        print("Ressource freigegeben");
    }

    // Copy-Konstruktor (Punkt 2)
    Resource(const Resource& other): m_ptr(new int(*other.m_ptr)) {
        print("Kopie erstellt");
    }

    // Copy-Assignment Operator (Punkt 3)
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete m_ptr; // Alte Resource freigeben
            m_ptr = new int(*other.m_ptr);
            print("Zuweisung durch Kopie");
        }
        return *this;
    }

    // Move-Konstruktor (Punkt 4)
    Resource(Resource&& other) noexcept : m_ptr(std::exchange(other.m_ptr, nullptr)) {
        print("Move-Konstruktor aufgerufen");
    }

    // Move-Assignment-Operator (Punkt 5)
    Resource& operator=(Resource &&other) noexcept {
        if ( this != &other ) {
            delete m_ptr;
            m_ptr = std::exchange(other.m_ptr, nullptr);
            print("Move-Assignment aufgerufen");
        }
        return *this;
    }

    [[nodiscard]] int value() const {
        if (!m_ptr) {
            print("Warnung: Zugriff auf nullptr!");
            return 0;
        }
        return *m_ptr;
    }

private:
    int* m_ptr;
};


int main() {
    SetConsoleOutputCP(CP_UTF8);

    Resource res1(10);
    Resource res2 = res1;  // copy - ctor
    Resource res3(20);
    res3 = res1; // Kopie
    print("Wert von res3:", res3.value());

    Resource res4 = std::move(res1); // move ctor
    Resource res5(30);
    print("Wert von res5:", res5.value());
    res5 = std::move(res1); // move-assignment
    print("Wert von res5 nach std::move:", res5.value());
}

/* Ausgabe
    Ressource für 20 erstellt
    Kopie erstellt
    Ressource für 10 erstellt
    Zuweisung durch Kopie
    Wert von res3: 10
    Move-Konstruktor aufgerufen
    Ressource für 30 erstellt
    Wert von res5: 30
    Move-Assignment aufgerufen
    Warnung: Zugriff auf nullptr!
    Wert von res5 nach std::move: 0
    Ressource freigegeben
    Ressource freigegeben
    Ressource freigegeben
    Ressource freigegeben
    Ressource freigegeben
 */
