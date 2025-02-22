#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>

namespace funcs {
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector) {
        os << "vector{";
        for ( int i = 0; i < vector.size(); i++) {
            os << vector[i] << ( i < vector.size() - 1 ? "," : "}");
        }
        return os;
    }

    template <typename ...Args>
    void print(Args ...args) {
        std::cout << std::boolalpha;
        ((std::cout << args << " "), ...) << std::endl;
    }



};


#endif //FUNCS_H
