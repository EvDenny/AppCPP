#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include <limits>
#include "Sleep.h"
#include "ArrayTutorial.h"
#include "menu.h"
#include "Guess.h"
#include "hangman.h"

#define underline "\033[4m"
#define reset "\033[0m"

void slp(int time) {
    if (time > 30) {
        Sleep::milliseconds(time);
    } else if (time > 0 && time <= 30) {
        Sleep::seconds(time);
    } else {
        return;
    }
}
void mainSUB() {
    if (mainPLAYBool) {
        mainNull;
        Menu::switchGame();
    } else if (mainTUTORBool) {
        mainNull;
        Menu::switchTutor();
    } else if (mainEXITBool) {
        Menu::exiting();
    }
}
void gameMenus() {
    if (gameGUESSBool) {
        gameNull;
        Menu::starting();
        do {
            Menu::run(Guessing_Game);
            std::cin.clear();
            system("clear");
            Menu::switchEndOfGame();
        } while (endOfGamePLAYAGAINBool);
    } else if (gameHANGMANBool) {
        gameNull;
        Menu::starting();
        do {
            Menu::run(HANGMAN::game);
            std::cin.clear();
            system("clear");
            Menu::switchEndOfGame();
        } while (endOfGamePLAYAGAINBool);
    } else if (gameEXITBool) {
        gameNull;
    }
}
void tutorMenus() {
    if (tutorARRAYBool) {
        tutorNull;
        Menu::starting();
        do {
            Menu::run(ArrayTutorial);
            std::cin.clear();
            system("clear");
            Menu::switchEndOfTutor();
        } while (endOfTutorAGAINBool);
    } else if (tutorEXITBool) {
        tutorNull;
    }
}
void clearMenuStates() {
    mainNull;
    gameNull;
    tutorNull;
    endOfGameNull;
    endOfTutorNull;
}

int main() {
    do {
        clearMenuStates();
        system("clear");
        Menu::switchMain();
        mainSUB();
        gameMenus();
        tutorMenus();
    } while (!(mainEXITBool) || !(gameEXITBool) || !(tutorEXITBool));
    system("clear");
    Menu::exiting();
}