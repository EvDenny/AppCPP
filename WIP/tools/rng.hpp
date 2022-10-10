#ifndef _RNG_HPP_
#define _RNG_HPP_
#include "../random.h"

class Rng
    {
    private:
        bool running = false;
        int input;
        int OUTPUT;
    public:
        Rng(bool running = false) : running(running) {};
        int a, b;
        std::mt19937 seeded_eng() { std::random_device rd; std::seed_seq seed{ rd(), rd(), rd(), rd(), rd() }; return std::mt19937(seed); };
        auto operator()(int a, int b) { std::mt19937 eng = seeded_eng(); std::uniform_int_distribution<int> dist(a, b); return dist(eng); };
        void displayMenu();
        void switchRange(Random Object, int input);
        void boolRunning();
        void setInput(int userInput);
        void setOutput(int output);
        void displayOutput();
        void setRun(bool ean);
        bool getRun();
        bool is_integer(int input); // Checks if input is an integer    
        int getInput();
    };

#endif