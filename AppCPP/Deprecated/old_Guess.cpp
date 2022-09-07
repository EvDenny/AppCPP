#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <random>

#define underline "\033[4m"
#define reset "\033[0m"

std::mt19937 seeded_eng() {
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    return std::mt19937(seed);
}

class Random {
private:
    std::mt19937 eng = seeded_eng();
public:
auto operator()(int a, int b) {
        std::uniform_int_distribution<int> dist(a, b);
        return dist(eng);
    }
};

//base high score for GUESSING GAME game 
int high_score_guessgame = 10;

//GUESSING GAME function
void Guessing_Game() {
    std::string selection;
    Random random;
    int number = random.operator()(1, 100);
    int guess = 0;
    int tries = 0;
    while (guess != number) {
        std::cout << underline "      GUESSING GAME      " reset << std::endl;
        Sleep::milliseconds(100);
        std::cout << "|--High Score-> " << high_score_guessgame << " tries." << std::endl; 
        std::cout << "|-Your tries-> " << tries << std::endl << std::endl;
        std::cout << "Guess a number between 1 and 100:\n" << "-> ";
        std::cin >> guess;
        if (guess == number) {
            tries++;
            std::cout << "Wow! You guessed the number in " << tries << " tries!" << std::endl;
            if (tries < high_score_guessgame) {
                high_score_guessgame = tries;
                std::cout << "New high score! " << high_score_guessgame << " tries" << std::endl;
            }
            Sleep::seconds(2);
            selection = "";
            while (selection != "1" && selection != "2") {
                system("clear");
                std::cout << underline "Play again?\n" reset << std::endl;
                std::cout << "1. Play" << std::endl;
                std::cout << "2. Go to Main Menu" << std::endl;
                std::cout << "3. Exit" << std::endl;
                std::cout << "-> ";
                getline(std::cin, selection);
                if (selection == "1") {
                    system("clear");
                    Guessing_Game();
                } else if (selection == "2") {
                    return;
                } else if (selection == "3") {
                    system("clear");
                    std::cout << "Thanks for playing!" << std::endl;
                    Sleep::seconds(1);
                    std::cout << "Exiting..." << std::endl;
                    Sleep::milliseconds(500);
                    std::cout << "Goodbye!" << std::endl;
                    Sleep::milliseconds(500);
                    system("clear");
                    exit(0);
                } else if (selection == "" || selection == " ") {
                    Sleep::milliseconds(10);
                } else {
                    std::cout << "Invalid selection" << std::endl;
                }
                Sleep::milliseconds(400);
                continue;
            }
        } else if (guess > 100 || guess < 1) { //implement way to quit game if user enters q or quit, e or exit, etc.
            std::cout << "Invalid guess! Try again..." << std::endl;
        } else if (abs(guess-number) >= 50) {
            tries++;
            std::cout << "You're freezing cold!" << std::endl;
        } else if (abs(guess-number) >= 25) {
            tries++;
            std::cout << "You're cold!" << std::endl;
        } else if (abs(guess-number) >= 15) {
            tries++;
            std::cout << "You're warm!" << std::endl;
        } else if (abs(guess-number) >= 10) {
            tries++;
            std::cout << "You're very warm!" << std::endl;
        } else if (abs(guess-number) >= 5) {
            tries++;
            std::cout << "You're hot!" << std::endl;
        } else if (abs(guess-number) >= 1) {
            tries++;
            std::cout << "You're very hot!" << std::endl;
        } else {
            //invalid character
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Sleep::milliseconds(1200); //Increased to 1200
        system("clear");
    }
}