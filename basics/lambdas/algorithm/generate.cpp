#include <ctime>
#include <random>
#include "../funcs.h"

using namespace funcs;
using std::generate, std::srand, std::rand, std::time, std::string, std::random_device, std::mt19937, std::bernoulli_distribution;

int main() {

    IntVector rndNums(10);
    srand(time(0));
    generate(rndNums.begin(), rndNums.end(), [](){ return rand() % 100; } );
    print(rndNums);

    int counter = 0;
    generate(rndNums.begin(), rndNums.end(), [&counter]() { return counter++; });
    print("Counter:", counter, rndNums);

    BoolVector bool_vector(10);
    random_device rnd;
    mt19937 gen(rnd());
    bernoulli_distribution dist(0.5);

    generate(bool_vector.begin(), bool_vector.end(), [&]() { return dist(gen);} );
    print("bernoulli_distribution -> bool_vector:", bool_vector);

    BoolVector2D boolGrid(8, BoolVector(10));

    for ( auto &row : boolGrid) {
        generate(row.begin(), row.end(), [&]() { return dist(gen); });
    }

    print("\nboolGrid:\n", boolGrid);

}

/* Ausgabe:
    vector{29,97,1,32,26,44,94,23,93,24}
    Counter: 10 vector{0,1,2,3,4,5,6,7,8,9}
    bernoulli_distribution -> bool_vector: vector{false,false,true,true,false,true,true,true,true,false}

    boolGrid:
     vector{vector{true,false,true,true,true,false,true,true,true,true},vector{false,true,true,true,true,false,false,true,tr
    ue,false},vector{false,true,false,true,true,false,true,true,false,true},vector{false,false,true,true,true,true,false,fal
    se,true,false},vector{true,false,true,true,true,false,false,false,true,true},vector{true,true,false,false,false,false,tr
    ue,false,false,true},vector{true,true,true,true,false,true,false,true,true,false},vector{true,true,false,true,false,fals
    e,true,true,false,true}}
 */