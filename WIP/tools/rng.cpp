#include <iostream>
#include <random>
#include <numeric>
#include <limits>
#include "../../main/menu.h"
using namespace std;

Random::static mt19937 seeded_eng() {
    seed_seq seed{rd(), rd(), rd(), rd(),rd(), rd(), rd(), rd()};
    return mt19937(seed);
}

Random::static auto operator()(int a, int b) {
    mt19937 eng = seeded_eng();
    uniform_int_distribution<int> dist(a, b);
    return dist(eng);
}

Random::static void displayMenu() {
    cout << "             RANDOM NUMBER GENERATOR              " << endl;
    cout << "Select a range to generate a random number within:" << endl;
    cout << "  (1) 1-10 | (2) 1-100 | (3) 1-1000 | (4) CUSTOM  " << endl;
    cout << "              (5) EXIT TO MAIN MENU               " << endl;
}

static void switchRange(int input) {
    setInput(input);
    int in = Random::getInput();
    switch (in) {
        case 1:
            cout << "Random number between 1 and 10: " << Random(1,10) << endl;
            break;
        case 2:
            cout << "Random number between 1 and 100: " << Random(1,100) << endl;
            break;
        case 3:
            cout << "Random number between 1 and 1000: " << Random(1,1000) << endl;
            break;
        case 4:
            int a, b;
            do {
            cout << "Enter a lower bound: ";
            cin >> a;
            while (a.isdigit()){
                cout << "Enter an upper bound: ";
                cin >> b;
                if (b.isdigit()){
                    cout << "Random number between " << a << " and " << b << ": " << Random(a,b) << endl;
                }
            }
            } while (a.isdigit() && b.isdigit());
            break;
        case 5:
            running = false;
            exit = true;
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
    }
    cin.clear();
}

Random::static void setInput(int userInput) {
    Random::input = userInput;
}

Random::static int getInput() {
    return Random::input;
}

Random::static void boolRunning() {
    if (running == true) {
        do {
            cout << ""
        }
    }
}