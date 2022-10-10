#include <iostream>
#include <random>
#include <numeric>
#include <limits>
#include "rng.hpp"
#include "../random.h"
using namespace std;

void Rng::displayMenu()
    {
    cout << "             RANDOM NUMBER GENERATOR              " << endl;
    cout << "Select a range to generate a random number within:" << endl;
    cout << "  (1) 1-10 | (2) 1-100 | (3) 1-1000 | (4) CUSTOM  " << endl;
    cout << "              (5) EXIT TO MAIN MENU               " << endl;
    }

void Rng::switchRange(Random Object, int input)
    {
    int in, output;
    std::cout << "Enter an input: ";
    std:cin >> in;
    switch (in)
        {
        case 1:
            output = Object(1,10);
            break;
        case 2:
            output = Object(1,100);
            break;
        case 3:
            output = Object(1,1000);
            break;
        case 4:
            std::cout << "Enter a lower bound: ";
            std::cin >> a;
            std::cout << "Enter an upper bound: ";
            std::cin >> b;
            output = Object(a, b);
            break;
        case 5:
            setRun(true);
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    setOutput(output);
    std::cin.clear();
    }

void Rng::setInput(int userInput)
    {
    Rng::input = userInput;
    }

int Rng::getInput()
    {
    std::cin >> Rng::input;
    return Rng::input;
    }

void Rng::boolRunning()
    {
    if (running == true)
        {
        do
            {
            cout << "";
            }
        while (running);
        }
    }

void Rng::setOutput(int output) {
    Rng::OUTPUT = output;
}

void Rng::displayOutput() {
    cout << "  Output: " << Rng::OUTPUT << endl;
}

void Rng::setRun(bool ean) {
    Rng::running = ean;
}

bool Rng::getRun() {
    return Rng::running;
}