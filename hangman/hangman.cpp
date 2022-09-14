
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <limits>
#include "hang.h"

#define underline "\033[4m"
#define reset "\033[0m"

class Sleep {
public:
    static void seconds(int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }
    static void milliseconds(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
    static void microseconds(int microseconds) {
        std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
    }
};

void copyToVector(const char * cstr, std::vector<char> &vector) {
    for (int i = 0; i < strlen(cstr); i++) {
        vector.push_back(cstr[i]);
    }
}

void removeChars(std::vector<char> &vector) {
    std::remove(vector.begin(), vector.end(), '?');
    std::remove(vector.begin(), vector.end(), '!');
    std::remove(vector.begin(), vector.end(), '.');
    std::remove(vector.begin(), vector.end(), ',');
    std::remove(vector.begin(), vector.end(), ';');
    std::remove(vector.begin(), vector.end(), ':');
    std::remove(vector.begin(), vector.end(), '@');
    std::remove(vector.begin(), vector.end(), '#');
    std::remove(vector.begin(), vector.end(), '&');
    std::remove(vector.begin(), vector.end(), '"');
    std::remove(vector.begin(), vector.end(), '(');
    std::remove(vector.begin(), vector.end(), ')');
} //Removes general characters from the vector that aren't letters.

void removeSpaceChar(std::vector<char> &vector) {
    std::remove(vector.begin(), vector.end(), ' ');
} //Removes instances of the space character from the vector.

void removeAposChar(std::vector<char> &vector) {
    std::remove(vector.begin(), vector.end(), '\'');
} //Removes any instances of the apostrophe from the vector. Passes vector address to the function.

void vectorToLower(std::vector<char> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = tolower(vector[i]);
    }
} //Makes all elements of the vector lowercase if able.

void vectorToLowerCopy(std::vector<char> &vector, std::vector<char> &copy) {
    for (int i = 0; i < vector.size(); i++) {
        copy.push_back(tolower(vector[i]));
    }
} //Adds elements to a new vector but modified to be lowercase.

void sortVector(std::vector<char> &vector) {
    std::sort(vector.begin(), vector.end());
} //Sorts vector in ascending order.

void uniqueCopyTo(std::vector<char> &vector, std::vector<char> &copy) {
    std::unique_copy(vector.begin(), vector.end(), copy.begin());
} //Eliminates consecutive duplicates and copies the modified vector to a new vector without the extra chars.

void printVector(std::vector<char> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i];
    }
}
struct Equalto {
    char c;
    Equalto(char d) : c(d) {}
    bool operator()(char d) {
        return d == c;
    }
}; //Checks if a char is equal to a certain char.

bool isInVector(std::vector<char> &vector, char c) {
    return std::any_of(vector.begin(), vector.end(), Equalto(c));
} //Checks if a char is in a vector.

char letter;
bool win = false;
bool correct;
int tries = 6;
std::vector<char> answer;
std::vector<char> right;
std::vector<char> wrong;
const char * strtochar;
std::vector<char> chars;
std::vector<char> charsLower;
std::string phrase;
std::string hint;

void initArray() {
    getline(std::cin, phrase);
    if (std::any_of(phrase.begin(), phrase.end(), [](char c) { return isdigit(c); })) {
        std::cout << "Error: Phrase contains non-letter characters." << std::endl;
        Sleep::seconds(1);
        exit(1);
    }
    const char *strtochar = phrase.c_str();
    copyToVector(strtochar, chars);
}

void loss() {
    std::cout << "You lose!" << std::endl;
    std::cout << "The word or phrase was: " << phrase << std::endl;
    std::cout << "Press ENTER to exit...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    exit(0);
}
void printHangman() {
    if (tries == 6) {
        draw6();
    } else if (tries == 5) {
        draw5();
    } else if (tries == 4) {
        draw4();
    } else if (tries == 3) {
        draw3();
    } else if (tries == 2) {
        draw2();
    } else if (tries == 1) {
        draw1();
    } else if (tries == 0) {
        draw0();
        loss();
    }
}
void printWrong() {
    for (int i = 0; i < wrong.size(); i++) {
        std::cout << wrong[i];
    }
    std::cout << std::endl;
}

void check() {
    correct = false;
    for (int i = 0; i < charsLower.size(); i++) {
        if (isInVector(charsLower, letter) && !isInVector(right, letter)) {
            correct = true;
            break;
        } else if (isInVector(right, letter)) {
            correct = true;
            break;
        } else {
            correct = false;
        }
    }
    if (correct == true && !isInVector(right, letter)) {
        std::cout << "Correct!" << std::endl;
        Sleep::seconds(1);
        right.push_back(letter);
        std::sort(right.begin(), right.end());
    } else if (correct == true && isInVector(right, letter)) {
        std::cout << "You already guessed that letter!" << std::endl;
        std::sort(right.begin(), right.end());
        Sleep::seconds(1);
    } else if (correct == false) {
        std::cout << "Wrong!" << std::endl;
        Sleep::seconds(1);
        wrong.push_back(letter);
        tries--;
    }
}
void checkWin() {
    if (right == answer) {
        win = true;
    }
}
void printLines2() {
    for (int i = 0; i < charsLower.size(); i++) {
        if (!isInVector(right, charsLower[i])) {
            if (charsLower[i] == ' ') {
                std::cout << " ";
            } else if (charsLower[i] == '\'') {
                std::cout << "\' ";
            } else if (charsLower[i] == '?') {
                std::cout << "? ";
            } else if (charsLower[i] == '!') {
                std::cout << "! ";
            } else if (charsLower[i] == '#') {
                std::cout << "#";
            } else if (charsLower[i] == '.') {
                std::cout << ". ";
            } else if (charsLower[i] == ',') {
                std::cout << ", ";
            } else if (charsLower[i] == ';') {
                std::cout << "; ";
            } else if (charsLower[i] == ':') {
                std::cout << ": ";
            } else if (charsLower[i] == '"') {
                std::cout << '"' << " ";
            } else if (charsLower[i] == '&') {
                std::cout << "& ";
            } else if (charsLower[i] == '(') {
                std::cout << "( ";
            } else if (charsLower[i] == ')') {
                std::cout << ") ";
            } else if (charsLower[i] == '-') {
                std::cout << "- ";
            } else if (charsLower[i] == '+') {
                std::cout << "+ ";
            } else if (charsLower[i] == '=') {
                std::cout << "= ";
            } else {
                std::cout << "_ ";
            }
        } else if (isInVector(right, charsLower[i])) {
            for (int j = 0; j < right.size(); j++) {
                if (right[j] == charsLower[i]) {
                    std::cout << underline << right[j] << reset << " ";
                }
            }
        }
    }
    std::cout << std::endl;
}
void getInput() {
    std::cout << "Guess a letter: ";
    std::cin.clear();
    std::cin >> letter;
    if (letter == '1' || letter == '2' || letter == '3' || letter == '4' || letter == '5' || letter == '6' || letter == '7' || letter == '8' || letter == '9' || letter == '0') {
        std::cout << "Invalid input" << std::endl;
        Sleep::seconds(1);
        system("clear");
        getInput();
    } else {
        letter = tolower(letter);
        check();
        checkWin();
        if (win == false) {
            win = false;
        } else if (win == true) {
            system("clear");
            printHangman();
            printWrong();
            printLines2();
            std::cout << "You win!" << std::endl;
            Sleep::milliseconds(500);
            std::cout << "You had " << tries << " lives left." << std::endl;
            std::cout << "The word or phrase was: " << phrase << std::endl;
            Sleep::seconds(2);
            std::cout << "Press ENTER to exit...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            exit(0);
        }
    }
}
void redraw() {
    system("clear");
    printHangman();
    printWrong();
    printLines2();
    getInput();
}
void play() {
    system("clear");
    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "Write your word or phrase: ";
    initArray();
    vectorToLower(chars);
    std::copy(chars.begin(), chars.end(), std::back_inserter(charsLower));
    removeChars(chars);
    removeAposChar(chars);
    removeSpaceChar(chars);
    sortVector(chars);
    std::unique_copy(chars.begin(), chars.end(), std::back_inserter(answer));
    do {
        redraw();
    } while (!win);
}
int main() {
    do {
    system("clear");
    std::cout << "  HANGMAN  " << std::endl;
    std::cout << "  --------  " << std::endl;
    std::cout << "  1. Play   " << std::endl;
    std::cout << "  2. Exit   " << std::endl;
    std::cout << "  --------  " << std::endl;
    std::cout << "> ";
    std::string selection;
    getline(std::cin, selection);
    if (selection == "1") {
        play();
    } else if (selection == "2") {
        std::cout << "Exiting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        exit(0);
    } else {
        std::cout << "Invalid selection." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    }
    } while (!win);
};