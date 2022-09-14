#ifndef _RNG_HPP_
#define _RNG_HPP_

class Random {
private:
    static std::random_device rd;
    bool running = true;
    bool exit = false;
    static int input;
public:
    static std::mt19937 seeded_eng();
    auto operator()(int a, int b);
    static void displayMenu();
    static void switchRange(int input);
    static void boolRunning();
    static void setInput(int userInput);
    static int getInput();
};

#endif