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
#include "mdy2.h"
#include "menu.h"
#include "Guess.h"
#include "hangman.h"
#include "clear.h"

#define underline "\033[4m"
#define reset "\033[0m"

//UPDATED 0.5.1_12
void mainSUB() {
    if (mainPLAYBool) {
        mainNull;
        Menu::switchGame();
    } else if (mainTOOLSBool) {
        mainNull;
        Menu::switchTools();
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
            cls();
            Menu::switchEndOfGame();
        } while (endOfGamePLAYAGAINBool);
    } else if (gameHANGMANBool) {
        gameNull;
        Menu::starting();
        do {
            Menu::run(HANGMAN::game);
            std::cin.clear();
            cls();
            Menu::switchEndOfGame();
        } while (endOfGamePLAYAGAINBool);
    } else if (gameEXITBool) {
        gameNull;
    }
}
void toolsMenus() {
    if (toolsMDYBool) {
        toolsNull;
        Menu::starting();
        do {
            Menu::run(CalendarTool);
            std::cin.clear();
            cls();
            Menu::switchEndOfTools();
        } while (endOfToolsAGAINBool);
    } else if (toolsEXITBool) {
        toolsNull;
    }
}
void clearMenuStates() {
    mainNull;
    gameNull;
    toolsNull;
    endOfGameNull;
    endOfToolsNull;
}

int main() {
    do {
        clearMenuStates();
        cls();
        Menu::switchMain();
        mainSUB();
        gameMenus();
        toolsMenus();
    } while (!(mainEXITBool) || !(gameEXITBool) || !(toolsEXITBool));
    cls();
    Menu::exiting();
}