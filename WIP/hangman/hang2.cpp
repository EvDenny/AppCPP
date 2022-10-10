#include <iostream>
#define underline "\033[4m"
#define reset "\033[0m"
using namespace std;

void head(int lives) {
    if (lives == 6) {
        cout << " ";
    } else {
        cout << "O";
    }
}

void torso(int lives) {
    if (lives > 4) {
        cout << "   ";
    } else if (lives > 3) {
        cout << " | ";
    } else if (lives > 2) {
        cout << "/| ";
    } else if (lives <= 2) {
        cout << "/|\\";
    }
}

void legs(int lives) {
    if (lives > 1) {
        cout << "   ";
    } else if (lives == 1) {
        cout << "/  ";
    } else if (lives == 0) {
        cout << "/ \\";
    }
}

void draw2(int lives) {
    cout << "     |=---=|" << endl;
    cout << "     "; head(lives); cout << "     |" << endl;
    cout << "    "; torso(lives); cout << "    |" << endl;
    cout << "    "; legs(lives); cout << "    |" << endl;
    cout << underline "           |" reset << endl;
    cout << underline "///////////|" reset << endl;
}

int main() {
    draw2(6);
    draw2(5);
    draw2(4);
    draw2(3);
    draw2(2);
    draw2(1);
    draw2(0);
    return 0;
}