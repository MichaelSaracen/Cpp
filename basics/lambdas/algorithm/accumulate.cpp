#include <numeric>

#include "../funcs.h"


using namespace funcs;
using std::accumulate, std::initializer_list, std::next;

template <typename ...Args>
auto sum(Args ...args) {
    return (args + ...);
}

template<typename T>
T sum(initializer_list<T> values) {
    if ( values.size() == 0 ) throw std::invalid_argument("List kann nicht leer sein");
    return accumulate(next(values.begin()), values.end(), *values.begin(), std::plus<T>());
}

template <typename First, typename  ...Args>
auto subtract(First first, Args ...args) {
    return (first - ... - args);
}

template<typename T>
T subtract(initializer_list<T> values) {
    if ( values.size() == 0 ) throw std::invalid_argument("List kann nicht leer sein");
    return accumulate(next(values.begin()), values.end(), *values.begin(), std::minus<T>());
}

int main() {
    print(sum(1,2,5));
    print(sum({2.3,3.3,4.3}));
    print(subtract(10,1,2,3));
    print(subtract({10,5,1}));
}