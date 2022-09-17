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
#define mainTUTOR menuOption = MainMenu::TUTOR
#define mainTUTORBool menuOption == MainMenu::TUTOR
#define mainEXIT menuOption = MainMenu::EXIT
#define mainEXITBool menuOption == MainMenu::EXIT

// TUTORIAL ENUMERATIONS
#define tutorNull tutorOption = TutorMenu::null
#define tutorNullBool tutorOption == TutorMenu::null
#define tutorARRAY tutorOption = TutorMenu::ARRAY
#define tutorARRAYBool tutorOption == TutorMenu::ARRAY
#define tutorEXIT tutorOption = TutorMenu::EXIT
#define tutorEXITBool tutorOption == TutorMenu::EXIT

// END OF GAME MENU ENUMERATIONS
#define endOfGameNull endOfGameOption = endOfGameMenu::null
#define endOfGameNullBool endOfGameOption == endOfGameMenu::null
#define endOfGamePLAYAGAIN endOfGameOption = endOfGameMenu::PLAY_AGAIN
#define endOfGamePLAYAGAINBool endOfGameOption == endOfGameMenu::PLAY_AGAIN
#define endOfGameEXIT endOfGameOption = endOfGameMenu::EXIT_TO_MAIN
#define endOfGameEXITBool endOfGameOption == endOfGameMenu::EXIT_TO_MAIN
#define endOfGameABORT endOfGameOption = endOfGameMenu::EXIT
#define endOfGameABORTBool endOfGameOption == endOfGameMenu::EXIT

// END OF TUTORIAL MENU ENUMERATIONS
#define endOfTutorNull endOfTutorOption = endOfTutorMenu::null
#define endOfTutorNullBool endOfTutorOption == endOfTutorMenu::null
#define endOfTutorAGAIN endOfTutorOption = endOfTutorMenu::TUTOR_AGAIN
#define endOfTutorAGAINBool endOfTutorOption == endOfTutorMenu::TUTOR_AGAIN
#define endOfTutorEXIT endOfTutorOption = endOfTutorMenu::EXIT_TO_MAIN
#define endOfTutorEXITBool endOfTutorOption == endOfTutorMenu::EXIT_TO_MAIN
#define endOfTutorABORT endOfTutorOption = endOfTutorMenu::EXIT
#endif // __MENU_OPTIONS__

#pragma once

#define underline "\033[4m"
#define reset "\033[0m"

enum class MainMenu {
    null,
    PLAY_GAMES,
    TUTOR,
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

enum class TutorMenu {
    null,
    ARRAY,
    EXIT
};

enum class endOfTutorMenu {
    null,
    TUTOR_AGAIN,
    EXIT_TO_MAIN,
    EXIT
};

MainMenu menuOption = MainMenu::null;
GameMenu gameOption = GameMenu::null;
TutorMenu tutorOption = TutorMenu::null;
endOfGameMenu endOfGameOption = endOfGameMenu::null;
endOfTutorMenu endOfTutorOption = endOfTutorMenu::null;

#include <iostream>
#include "Sleep.h"
#include "clear.h"

std::string invalid = "Invalid input, please try again";

class Menu {
public:
    static void run(void program()) {
        program();
    }
    static void displayMainMenu() {
        std::cout << "Welcome to " << underline "Evan" reset << " " << underline "Denny" reset << "'s App!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Games" << std::endl;
        std::cout << "2. Tutorials" << std::endl;
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
    static void displayTutorMenu() {
        std::cout << "Please select a tutorial to play:" << std::endl;
        std::cout << "1. Array Tutorial" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "-> ";
    }
    static void displayEndOfGameMenu() {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Again" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "-> ";
    }
    static void displayEndOfTutorMenu() {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Tutorial Again?" << std::endl;
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
                mainTUTOR;
                break;
            case 3:
                exiting();
                break;
            default:
                mainNull;
                invalidInput();
                cls();
                break;
        }
	    std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (gameNullBool);
        cls();
    }
    static void switchTutor() {
        int input;
        do {
        displayTutorMenu();
        std::cin >> input;
        switch (input) {
            case 1:
                tutorARRAY;
                break;
            case 2:
                tutorEXIT;
                break;
            default:
                tutorNull;
                invalidInput();
                cls();
                break;
        }
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        } while (tutorNullBool);
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
                Menu::exiting();
                break;
            default:
                endOfGameNull;
                invalidInput();
                cls();
                break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        } while (endOfGameNullBool);
        cls();
    }
    static void switchEndOfTutor() {
        int input;
        do {
        displayEndOfTutorMenu();
        std::cin >> input;
        switch (input) {
            case 1:
                endOfTutorAGAIN;
                break;
            case 2:
                endOfTutorEXIT;
                break;
            case 3:
                endOfTutorABORT;
		        Menu::exiting();
                break;
            default:
                endOfTutorNull;
                invalidInput();
                cls();
                break;
}
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        } while (endOfTutorNullBool);
        cls();
    }
    static void starting() {
        std::cout << "Starting Program..." << std::endl;
        Sleep::milliseconds(600);
        std::cout << "LOADED." << std::endl;
        Sleep::milliseconds(350);
        cls();
    }
    static void exiting() {
        std::cout << "Exiting..." << std::endl;
        Sleep::milliseconds(500);
        std::cout << "Goodbye!" << std::endl;
        Sleep::seconds(1);
        cls();
        exit(0);
    }
};

#endif
