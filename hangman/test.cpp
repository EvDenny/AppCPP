#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <array>

std::string phrase;

void copyToVector(const char * cstr, std::vector<char> &vector) {
    for (int i = 0; i < strlen(cstr); i++) {
        vector.push_back(cstr[i]);
    }
}

std::vector<char> phraseVector;

int main() {
    std::cout << "Enter a phrase: ";
    getline(std::cin, phrase);
    const char *strtochar = phrase.c_str();
    for (int i = 0; i < phrase.length(); i++) {
        std::cout << strtochar[i] << " ";
    }
    std::cout << std::endl;
    copyToVector(strtochar, phraseVector);
    for (int i = 0; i < phraseVector.size(); i++) {
        std::cout << phraseVector[i];
    }
    std::cout << std::endl;
    return 0;
}