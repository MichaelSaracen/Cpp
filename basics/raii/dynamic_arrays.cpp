#include <iostream>

using namespace std;

class ArrayWrapper {
public:
    ArrayWrapper(size_t n);
    ~ArrayWrapper();

private:
    int *m_data;
    size_t m_size;
};

ArrayWrapper::ArrayWrapper(size_t n) : m_data(new int[n]), m_size(n) {
    cout << "Array mit " << m_size << " Elementen reserviert\n";
}

ArrayWrapper::~ArrayWrapper() {
    cout << "Array mit " << m_size << " Elementen freigegeben.\n";
    delete[] m_data;
}



int main() {
    ArrayWrapper(5);
}