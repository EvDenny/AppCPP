#ifndef _menu_h
#define _menu_h

#include "clear.h"

#ifndef __MENU_OPTIONS__
//_________________MENU_ENUMS___________________
// GAME MENU ENUMERATIONS
#define gameEXIT gameOption = GameMenu::EXIT
#define gameEXITBool gameOption == GameMenu::EXIT
#define gameNull gameOption = GameMenu::null
#define gameNullBool gameOption == GameMenu::null
#define gameGUESS gameOption = GameMenu::GUESS
#define gameGUESSBool gameOption == GameMenu::GUESS
#define gameHANGMAN gameOption = GameMenu::HANGMAN
#define gameHANGMANBool gameOption == GameMenu::HANGMAN

// MAIN MENU ENUMERATIONS
#define mainNull menuOption = MainMenu::null
#define mainNullBool menuOption == MainMenu::null
#define mainPLAY menuOption = MainMenu::PLAY_GAMES
#define mainPLAYBool menuOption == MainMenu::PLAY_GAMES
#define mainTOOLS menuOption = MainMenu::TOOLS
#define mainTOOLSBool menuOption == MainMenu::TOOLS
#define mainEXIT menuOption = MainMenu::EXIT
#define mainEXITBool menuOption == MainMenu::EXIT

// TOOLS ENUMERATIONS
#define toolsNull toolsOption = ToolsMenu::null
#define toolsNullBool toolsOption == ToolsMenu::null
#define toolsMDY toolsOption = ToolsMenu::MDY
#define toolsMDYBool toolsOption == ToolsMenu::MDY
#define toolsEXIT toolsOption = ToolsMenu::EXIT
#define toolsEXITBool toolsOption == ToolsMenu::EXIT

// END OF GAME MENU ENUMERATIONS
#define endOfGameNull endOfGameOption = endOfGameMenu::null
#define endOfGameNullBool endOfGameOption == endOfGameMenu::null
#define endOfGamePLAYAGAIN endOfGameOption = endOfGameMenu::PLAY_AGAIN
#define endOfGamePLAYAGAINBool endOfGameOption == endOfGameMenu::PLAY_AGAIN
#define endOfGameEXIT endOfGameOption = endOfGameMenu::EXIT_TO_MAIN
#define endOfGameEXITBool endOfGameOption == endOfGameMenu::EXIT_TO_MAIN
#define endOfGameABORT endOfGameOption = endOfGameMenu::EXIT
#define endOfGameABORTBool endOfGameOption == endOfGameMenu::EXIT

// END OF TOOLS MENU ENUMERATIONS
#define endOfToolsNull endOfToolsOption = endOfToolsMenu::null
#define endOfToolsNullBool endOfToolsOption == endOfToolsMenu::null
#define endOfToolsAGAIN endOfToolsOption = endOfToolsMenu::USE_AGAIN
#define endOfToolsAGAINBool endOfToolsOption == endOfToolsMenu::USE_AGAIN
#define endOfToolsEXIT endOfToolsOption = endOfToolsMenu::EXIT_TO_MAIN
#define endOfToolsEXITBool endOfToolsOption == endOfToolsMenu::EXIT_TO_MAIN
#define endOfToolsABORT endOfToolsOption = endOfToolsMenu::EXIT
#define endOfToolsABORTBool endOfToolsOption == endOfToolsMenu::EXIT
#endif // __MENU_OPTIONS__

#pragma once

#define underline "\033[4m"
#define reset "\033[0m"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

enum class MainMenu {
    null,
    PLAY_GAMES,
    TOOLS,
    EXIT
};

enum class GameMenu {
    null,
    GUESS,
    HANGMAN,
    EXIT
};

enum class endOfGameMenu {
    null,
    PLAY_AGAIN,
    EXIT_TO_MAIN,
    EXIT
};

enum class ToolsMenu {
    null,
    MDY,
    EXIT
};

enum class endOfToolsMenu {
    null,
    USE_AGAIN,
    EXIT_TO_MAIN,
    EXIT
};

MainMenu menuOption = MainMenu::null;
GameMenu gameOption = GameMenu::null;
ToolsMenu toolsOption = ToolsMenu::null;
endOfGameMenu endOfGameOption = endOfGameMenu::null;
endOfToolsMenu endOfToolsOption = endOfToolsMenu::null;

#include <iostream>
#include "Sleep.h"
#include "clear.h"

std::string invalid = "Invalid input, please try again";

class Menu {
public:
    static void start_ending(int value) {
        switch (value) {
            case 0:
                std::cout << "Starting program..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(400));
                std::cout << "Loaded." << std::endl;
                cls();
                break;
            case 1:
                std::cout << "EXITING..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(400));
                std::cout << "Goodbye!" << std::endl;
                cls();
                exit(0);
                break;
        }
    }
    static void run(void program()) {
        program();
    }
    static void displayMainMenu() {
        std::cout << "Welcome to " << underline "Evan" reset << " " << underline "Denny" reset << "'s App!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Games" << std::endl;
        std::cout << "2. Tools" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "-> ";
    }
    static void displayGameMenu() {
        std::cout << "Please select a game to play:" << std::endl;
        std::cout << "1. Guessing Game" << std::endl;
        std::cout << "2. Hangman" << std::endl;
        std::cout << "3. Exit to Main Menu" << std::endl;
        std::cout << "-> ";
    }
    static void displayEndOfGameMenu() {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Again" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "-> ";
    }
    static void displayToolsMenu() {
        std::cout << "Please select tool to use:" << std::endl;
        std::cout << "1. Date Calculator" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "-> ";
    }
    static void displayEndOfToolsMenu() {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Use Tool Again" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "-> ";
    }
    static void invalidInput() {
        std::cout << invalid << std::endl;
        Sleep::seconds(1);
    }
    static void switchMain() {
        int input;
        do {
            displayMainMenu();
            std::cin >> input;
            switch (input) {
                case 1:
                    mainPLAY;
                    break;
                case 2:
                    mainTOOLS;
                    break;
                case 3:
                    start_ending(1);
                    break;
                default:
                    mainNull;
                    invalidInput();
                    cls();
                    break;
                }
            clearInput();
        } while (mainNullBool);
        cls();
    }
    static void switchGame() {
        int input;
        do {
            displayGameMenu();
            std::cin >> input;
            switch (input) {
                case 1:
                    gameGUESS;
                    break;
                case 2:
                    gameHANGMAN;
                    break;
                case 3:
                    gameEXIT;
                    break;
                default:
                    gameNull;
                    invalidInput();
                    cls();
                    break;
                }
            clearInput();
        } while (gameNullBool);
        cls();
    }
    static void switchTools() {
        int input;
        do {
            displayToolsMenu();
            std::cin >> input;
            switch (input) {
                case 1:
                    toolsMDY;
                    break;
                case 2:
                    toolsEXIT;
                    break;
                default:
                    toolsNull;
                    invalidInput();
                    cls();
                    break;
                }
            clearInput();
        } while (toolsNullBool);
        cls();
    }
    static void switchEndOfGame() {
        int input;
        do {
            displayEndOfGameMenu();
            std::cin >> input;
            switch (input) {
                case 1:
                    endOfGamePLAYAGAIN;
                    break;
                case 2:
                    endOfGameEXIT;
                    break;
                case 3:
                    cls();
                    Menu::start_ending(1);
                    break;
                default:
                    endOfGameNull;
                    invalidInput();
                    cls();
                    break;
                }
            clearInput();
        } while (endOfGameNullBool);
        cls();
    }

    static void switchEndOfTools() {
        int input;
        do {
            displayEndOfToolsMenu();
            std::cin >> input;
            switch (input) {
                case 1:
                    endOfToolsAGAIN;
                    break;
                case 2:
                    endOfToolsEXIT;
                    break;
                case 3:
                    endOfToolsABORT;
                    Menu::start_ending(1);
                    break;
                default:
                    endOfToolsNull;
                    invalidInput();
                    cls();
                    break;
                }
            clearInput();
        } while (endOfToolsNullBool);
        cls();
    }
};

#endif
