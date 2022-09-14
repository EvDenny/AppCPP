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
#include "Sleep.h"
#include "vectors.h"
#include "hangman.h"

#define underline "\033[4m"
#define reset "\033[0m"

char letter;
bool win = false;
bool correct;
int tries = 6;
std::vector<char> answer;
std::vector<char> right;
std::vector<char> wrong;
std::vector<char> chars;
std::vector<char> charsLower;
std::string phrase;
std::string hint;

void HANGMAN::printHint() {
    std::cout << "Hint: " << hint << std::endl;
}

void HANGMAN::initArray() {
    getline(std::cin, phrase);
    if (std::any_of(phrase.begin(), phrase.end(), [](char c) { return isdigit(c); })) {
        std::cout << "Error: Phrase contains non-letter characters." << std::endl;
        Sleep::seconds(1);
        exit(0);
    }
    const char *strtochar = phrase.c_str();
    copyToVector(strtochar, chars);
}

void HANGMAN::loss() {
    std::cout << "You lose!" << std::endl;
    std::cout << "The word or phrase was: " << phrase << std::endl;
    std::cout << "Press ENTER to exit...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    exit(0);
}
void HANGMAN::printHangman() {
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
void HANGMAN::printWrong() {
    for (int i = 0; i < wrong.size(); i++) {
        std::cout << wrong[i];
    }
    std::cout << std::endl;
}
void HANGMAN::check() {
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
void HANGMAN::checkWin() {
    if (right == answer) {
        win = true;
    }
}
void HANGMAN::printLines2() {
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

void HANGMAN::getInput() {
    std::cout << "Guess a letter: ";
    std::cin.clear();
    std::cin >> letter;
    if (letter == '1' || letter == '2' || letter == '3' || letter == '4' || letter == '5' || letter == '6' || letter == '7' || letter == '8' || letter == '9' || letter == '0' || letter == '!' || letter =='?' || letter == '+' || letter == '-' || letter == '_' || letter == '#' || letter == '&' || letter == '*' || letter == '=' || letter == '.' || letter == ',' || letter == '\'' || letter == '"' || letter == '(' || letter == ')') {
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
            system("clear");
        }
    }
}

void HANGMAN::printAns() {
    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i];
    }
    std::cout << "|";
    for (int i = 0; i < right.size(); i++) {
        std::cout << right[i];
    }
    std::cout << std::endl;
}

void HANGMAN::redraw() {
    system("clear");
    printHangman();
    printWrong();
    printLines2();
    //printAns();//For Debugging
    printHint();
    getInput();
}

void HANGMAN::play() {
    system("clear");
    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "Write your word or phrase: ";
    initArray();
    std::cin.clear();
    std::cout << "Write a hint for the word or phrase: ";
    getline(std::cin, hint);
    vectorToLower(chars);
    std::copy(chars.begin(), chars.end(), std::back_inserter(charsLower));
    removeChars(chars);
    removeAposChar(chars);
    removeSpaceChar(chars);
    sortVector(chars);
    std::vector<char> transfer;
    std::unique_copy(chars.begin(), chars.end(), std::back_inserter(transfer));
    removeSpaceChar(transfer);
    removeAposChar(transfer);
    removeChars(transfer);
    std::sort(transfer.begin(), transfer.end());
    std::unique_copy(transfer.begin(), transfer.end(), std::back_inserter(answer));
    do {
        redraw();
    } while (!win);
}

void HANGMAN::game() {
    bool gameOVER = false;
    do {
    system("clear");
    std::cout << "  HANGMAN   " << std::endl;
    std::cout << "  --------  " << std::endl;
    std::cout << "  1. Play   " << std::endl;
    std::cout << "  2. Exit   " << std::endl;
    std::cout << "  --------  " << std::endl;
    std::cout << "> ";
    std::string selection;
    std::cin.clear();
    getline(std::cin, selection);
    if (selection == "1") {
        play();
    } else if (selection == "2") {
        std::cout << "Exiting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        gameOVER = true;
    } else {
        std::cout << "Invalid selection." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    }
    } while (gameOVER = false);
    answer.clear();
    right.clear();
    wrong.clear();
    chars.clear();
    charsLower.clear();
    hint.clear();
    phrase.clear();
    win = false;
    tries = 6;
    correct = false;
    std::cin.clear();
}
