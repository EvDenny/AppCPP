#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <random>

std::mt19937 seeded_eng() {
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(),rd()};
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

int main () {
    Random random;
    int number = random(1,100);
    std::cout << number << std::endl;
    std::cout << "FLOAT SIZE: " << sizeof(float) << std::endl;
    std::cout << "Fuck" << std::endl;
    return 0;
}