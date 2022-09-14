#include <iostream>
#include <random>
#include <numeric>
#include <limits>
#include "rng.hpp"
using namespace std;

int main() {
    bool running = true;
    bool exit = false;
    do {
        Random::displayMenu();
        cout << "-> ";
        int input;
        cin >> input;
        Random::switchRange(input);
    } while (running == true);

}