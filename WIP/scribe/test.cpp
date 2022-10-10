#include <iostream>
#include <random>
#include <tuple>

tuple<int, int, int> triple;
triple = (0,0,0);

int main(){
    std::cout << triple << std::endl;
    return 0;
}