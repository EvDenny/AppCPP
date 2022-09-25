#include <iostream>
#include <random>
#include <numeric>
#include <limits>
#include "rng.hpp"
using namespace std;

void Random::displayMenu()
    {
    cout << "             RANDOM NUMBER GENERATOR              " << endl;
    cout << "Select a range to generate a random number within:" << endl;
    cout << "  (1) 1-10 | (2) 1-100 | (3) 1-1000 | (4) CUSTOM  " << endl;
    cout << "              (5) EXIT TO MAIN MENU               " << endl;
    }

void Random::switchRange(Random Object, int input)
    {
    int in;
    std::cout << "Enter an input: ";
std:cin >> in;
    switch (in)
        {
        case 1:
            std::cout << "Random number between 1 and 10: " << Object(1, 10) << endl;
            break;
        case 2:
            std::cout << "Random number between 1 and 100: " << Object(1, 100) << endl;
            break;
        case 3:
            std::cout << "Random number between 1 and 1000: " << Object(1, 1000) << endl;
            break;
        case 4:
            int output;
            do
                {
                std::cout << "Enter a lower bound: ";
                std::cin >> a;
                while (isdigit(a))
                    {
                    std::cout << "Enter an upper bound: ";
                    std::cin >> b;
                    if (isdigit(b))
                        {
                        output = Object(a, b);
                        std::cout << "Random number between " << a << " and " << b << ": " << output << endl;
                        }
                    }
                }
            while (isdigit(a) && isdigit(b));
                break;
        case 5:
            running = false;
            exit = true;
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    std::cin.clear();
    }

void Random::setInput(int userInput)
    {
    Random::input = userInput;
    }

int Random::getInput()
    {
    std::cin >> Random::input;
    return Random::input;
    }

void Random::boolRunning()
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


int main()
    {
    Random object;
    Random(object).switchRange(object, Random(object).getInput());
    return 0;
    }