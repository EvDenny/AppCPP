#ifndef _hangman_h_
#define _hangman_h_

#include <algorithm>
class HANGMAN {
public:
	static void game();
	static void initArray();
	static void loss();
	static void printHangman();
	static void printWrong();
	static void check();
	static void checkWin();
	static void printLines();
	static void getInput();
	static void redraw();
	static void play();
	static void printHint();
	static void printAns();
};

#endif