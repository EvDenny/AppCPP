#ifndef _RNG_HPP_
#define _RNG_HPP_

class Random
    {
    private:
        bool running = true;
        bool exit = false;
        int input;
    public:
        Random(bool running = true, bool exit = false) : running(running), exit(exit) {};
        int a, b;
        std::mt19937 seeded_eng() { std::random_device rd; std::seed_seq seed{ rd(), rd(), rd(), rd(), rd() }; return std::mt19937(seed); };
        auto operator()(int a, int b) { std::mt19937 eng = seeded_eng(); std::uniform_int_distribution<int> dist(a, b); return dist(eng); };
        void displayMenu();
        void switchRange(Random Object, int input);
        void boolRunning();
        void setInput(int userInput);
        bool is_integer(int input); // Checks if input is an integer    
        int getInput();
    };

#endif