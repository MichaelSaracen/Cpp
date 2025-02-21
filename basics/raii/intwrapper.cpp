#include <iostream>
using namespace std;


// Ressource im Konstruktor erwerben und im Destruktor releasen.
class IntWrapper {
public:
    explicit IntWrapper(int value);
    ~IntWrapper();
    [[nodiscard]] int getValue() const;
private:
    int *m_ptr;
};

IntWrapper::IntWrapper(int value) : m_ptr(new int(value)) {
    cout << "Ressource erworben: " << *m_ptr << endl;
}

IntWrapper::~IntWrapper() {
    cout << "Ressource freigegeben: " << *m_ptr << endl;
    delete m_ptr;
}

/**
 * Gibt den Wert wieder. Zeiger dereferenziert.
 * @return
 */
int IntWrapper::getValue() const { return *m_ptr; }

int main() {
    IntWrapper obj(54);
    cout << "Wert von obj.getValue(): " << obj.getValue() << endl;
}

/*
    Ressource erworben: 54
    Wert von obj.getValue(): 54
    Ressource freigegeben: 54
 */