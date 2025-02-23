#include <ctime>
#include "../funcs.h"

using namespace funcs;
using std::generate, std::srand, std::rand, std::time, std::string;

int main() {
    IntVector rndNums(10);
    srand(time(0));
    generate(rndNums.begin(), rndNums.end(), [](){ return rand() % 100; } );
    print(rndNums);

    int counter = 0;
    generate(rndNums.begin(), rndNums.end(), [&counter]() { return counter++; });
    print("Counter:", counter, rndNums);
}