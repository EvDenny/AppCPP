#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <random>

#include "Sleep.h"
#include "Guess.h"

#define underline "\033[4m"
#define reset "\033[0m"

std::mt19937 seeded_eng() {
	std::random_device rd;
	std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
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

int high_score_guessgame = 10;

void Guessing_Game() {
	std::string selection;
	Random random;
	int number = random.operator()(1, 100);
	int guess = 0;
	int tries = 0;
	do {
		system("clear");
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
			Sleep::milliseconds(200);
			if (tries <= high_score_guessgame) {
				std::cout << "YOU WIN!!!\nWow! You guessed the number in " << tries << " tries!\n";
				std::cout << "NEW HIGH SCORE!" << std::endl;
				high_score_guessgame = tries;
			} else if (tries > high_score_guessgame) {
				std::cout << "You guessed the number in " << tries << " tries!" << std::endl;
			}
			Sleep::seconds(1);
		}
		Sleep::milliseconds(1500);
	} while (number != guess);
}
