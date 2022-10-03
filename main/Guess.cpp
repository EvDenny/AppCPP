#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <limits>
#include <numeric>
#include <random>
#include "clear.h"
#include "Sleep.h"
#include "Guess.h"
#include "random.h"

#define underline "\033[4m"
#define reset "\033[0m"

int high_score_guessgame = 10;

void Guessing_Game() {
	std::string selection;
	Random random;
	int number = random(1, 100);
	int guess = 0;
	int tries = 0;
	do {
		cls();
		std::cout << underline "          GUESSING   GAME          " reset << std::endl;
		Sleep::milliseconds(50);
		std::cout << "|---HIGH-SCORE---> " << high_score_guessgame << " tries." << std::endl;
		std::cout << "|-YOUR-TRIES-> " << tries << std::endl << std::endl;
		std::cout << "Guess a number between 1 and 100:\n" << "-> ";
		std::cin >> guess;
		if (guess > 100 || guess < 1) {
			std::cout << "Invalid input! Try again..." << std::endl;
		} else if (abs(guess-number) >= 50) {
			tries++;
			std::cout << "You're freezing cold!" << std::endl;
		} else if (abs(guess-number) >= 25) {
			tries++;
			std::cout << "You're cold!" << std::endl;
		} else if (abs(guess-number) >= 15) {
			tries++;
			std::cout << "You're getting warmer..." << std::endl;
		} else if (abs(guess-number) >= 10) {
			tries++;
			std::cout << "It's getting very warm!" << std::endl;
		} else if (abs(guess-number) >= 5) {
			tries++;
			std::cout << "It's really hot!" << std::endl;
		} else if (abs(guess-number) >= 3) {
			tries++;
			std::cout << "It's REALLY hot!!!" << std::endl;
		} else if (abs(guess-number) >= 1) {
			tries++;
			std::cout << "YOU'RE ON FIRE!!!" << std::endl;
		} else if (guess == number) {
			++tries;
			if (tries <= high_score_guessgame) {
				std::cout << "YOU WIN!!!\nWow! You guessed the number in " << tries << " tries!\n";
				std::cout << "NEW HIGH SCORE!" << std::endl;
				high_score_guessgame = tries;
			} else if (tries > high_score_guessgame) {
				std::cout << "You guessed the number in " << tries << " tries!" << std::endl;
			}
			Sleep::milliseconds(2000);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		Sleep::milliseconds(400);
	} while (number != guess);
}
