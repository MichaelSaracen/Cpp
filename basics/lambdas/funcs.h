#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int age;
};

namespace funcs {

    using PersonVector = std::vector<Person>;
    using IntVector = std::vector<int>;
    using StringVector = std::vector<std::string>;
    using BoolVector = std::vector<bool>;
    using BoolVector2D = std::vector<std::vector<bool>>;

    inline std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Person{name=" << person.name << ", age=" << person.age << "}";
        return os;
    }

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
}

#endif //FUNCS_H
