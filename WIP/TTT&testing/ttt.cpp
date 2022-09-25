#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <random>
#include <limits>
#include "flip.h"

#define under "\033[4m"
#define _under "\033[0m"

using namespace std;

std::mt19937 seeded_eng()
   {
   std::random_device rd;
   std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd() };
   return std::mt19937(seed);
   }

class Random
   {
   private:
      std::mt19937 eng = seeded_eng();
   public:
      auto operator()(int a, int b)
         {
         std::uniform_int_distribution<int> dist{ a, b };
         return dist(eng);
         }
   };

vector<vector<char>> board{ {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

char TL = board[0][0];
char T = board[1][0];
char TR = board[2][0];
char ML = board[0][1];
char M = board[1][1];
char MR = board[2][1];
char BL = board[0][2];
char B = board[1][2];
char BR = board[2][2];

void drawBoard()
   {
   cout << "    |   " << under << board[0][0] << '|' << board[1][0] << '|' << board[2][0] << _under << "   |" << endl;
   cout << "    |   " << under << board[0][1] << '|' << board[1][1] << '|' << board[2][1] << _under << "   |" << endl;
   cout << "    |   " << board[0][2] << '|' << board[1][2] << '|' << board[2][2] << "   |" << endl << endl;
   }

void redraw()
   {
   cout << "     " << under "TIC-TAC-TOE" _under << "     " << endl << endl;
   drawBoard(); cout << endl;
   }

int randomFlip()
   {
   Random random;
   int fiftyfifty = random(1, 100);
   return fiftyfifty;
   }

void animationFlip(bool& h, bool& t)
   {
   drawing();
   system("cls");
   if (h == true)
      {
      frameH();
      }
   else if (t == true)
      {
      frameT();
      }
   std::this_thread::sleep_for(std::chrono::milliseconds(800));
   system("cls");
   }

void flipCoin()
   {
   int ht;
   bool cont = false;
   do
      {
      system("cls");
      cout << "               " << under " Flip a coin! " _under << "               " << endl;
      cout << " Choose between yourselves who will call the flip. " << endl << endl;
      cout << "     Select (" << under "1" _under << ") for HEADS and (" << under "2" _under << ") for TAILS " << endl << endl << endl << endl;
      cout << "-> ";
      cin >> ht;
      switch (ht)
         {
         case 1:
            ht = 1;
            break;
         case 2:
            ht = 2;
            break;
         default:
            cout << "         INVALID INPUT! Try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            this_thread::sleep_for(chrono::milliseconds(400));
            break;
         }
      if (ht == 1 || ht == 2)
         {
         cont = true;
         }
      }
   while (cont == false);
      int flip = randomFlip();
      bool heads = false; bool tails = false;
      if (flip > 50)
         {
         heads = true;
         }
      else if (flip <= 50)
         {
         tails = true;
         }
      animationFlip(heads, tails);
      system("cls");
      if ((heads == true && ht == 1) || (tails == true && ht == 2))
         {
         cout << "You guessed CORRECTLY!" << endl << "   You are the X's." << endl << "    X goes first." << endl << endl;
         }
      else
         {
         cout << "You guessed INCORRECTLY!" << endl << "   You are the O's." << endl << "    O goes second." << endl << endl;
         }
   }

void switchXY(char XO, int x, int y)
   {
   switch (x)
      {
      case 0:
         switch (y)
            {
            case 0:
               BL = XO;
               break;
            case 1:
               ML = XO;
               break;
            case 2:
               TL = XO;
               break;
            }
         break;
      case 1:
         switch (y)
            {
            case 0:
               B = XO;
               break;
            case 1:
               M = XO;
               break;
            case 2:
               T = XO;
               break;
            }
         break;
      case 2:
         switch (y)
            {
            case 0:
               BR = XO;
               break;
            case 1:
               MR = XO;
               break;
            case 2:
               TR = XO;
               break;
            }
         break;
      }
   }

void inputXY(char XO)
   {
   bool input = false;
   int x, y;
   do
      {
      cout << "(x)->";
      cin >> x;
      if (x <= 2 && x >= 0)
         {
         cout << "(y)->";
         cin >> y;
         if (y <= 2 && y >= 0)
            {
            switchXY(XO, x, y);
            }
         }
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   while (!input);
   }

enum class Main
   {
   Null = 0,
   PLAY,
   HELP,
   QUIT
   };

enum class PlayMode
   {
   Null = 0,
   COMPUTER,
   HUMAN,
   EXIT
   };

Main MAIN = Main::Null;
PlayMode PLAY = PlayMode::Null;

void menu()
   {
   int main;
   do
      {
      system("cls");
      redraw();
      cout << under "        MAIN MENU        " _under << endl;
      cout << " (1)PLAY (2)HELP (3)QUIT " << endl << endl;
      cout << "         ->";
      cin >> main;
      switch (main)
         {
         case 1:
            MAIN = Main::PLAY;
            break;
         case 2:
            MAIN = Main::HELP;
            break;
         case 3:
            MAIN = Main::QUIT;
            break;
         default:
            MAIN = Main::Null;
            cout << " Invalid Input! Try Again... " << endl;
            this_thread::sleep_for(chrono::milliseconds(400));
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
         }
      }
   while (MAIN == Main::Null);
   }



void gameMenu()
   {
   if (MAIN == Main::PLAY)
      {
      int play;
      do
         {
         system("cls");
         this_thread::sleep_for(chrono::milliseconds(125));
         cout << " (1) " << under "Versus-Computer | Versus-Human" _under << " (2) " << endl;
         cout << "               (3)Exit to Main Menu                " << endl;
         cout << "                     ->";
         cin >> play;
         switch (play)
            {
            case 1:
               PLAY = PlayMode::COMPUTER;
               break;
            case 2:
               PLAY = PlayMode::HUMAN;
               break;
            case 3:
               PLAY = PlayMode::EXIT;
               break;
            default:
               PLAY = PlayMode::Null;
               cout << "           Invalid Input! Try again..." << endl;
               this_thread::sleep_for(chrono::milliseconds(400));
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               break;
            }
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         if (PLAY == PlayMode::COMPUTER)
            {
            cout << "This mode is a work in progress..." << endl;
            PLAY = PlayMode::Null;
            }
         }
      while (PLAY == PlayMode::Null);
      }
   }

int main()
   {
   flipCoin();
   drawBoard();
   this_thread::sleep_for(chrono::seconds(2));
   board[0][1] = 'X';
   system("cls");
   redraw();
   return 0;
   }