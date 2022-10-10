#include <iostream>
#include <random>
#include <numeric>
#include <limits>
#include "rng.hpp"
#include "../random.h"
#include "../../main/clear.h"
using namespace std;

Rng RANDOM;
Random rng;

int main() {
    do {
        int input;
        RANDOM.displayMenu();
        RANDOM.displayOutput();
        RANDOM.switchRange(rng, input);
        cls();
    } while (!RANDOM.getRun());
    
}