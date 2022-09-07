#ifndef _VECTORS_H_
#define _VECTORS_H_

#include <vector>
#include <cstring>
#include <iostream>
#include <string.h>

void copyToVector(const char * cstr, std::vector<char> &vector) {
    for (int i = 0; i < strlen(cstr); i++) {
        vector.push_back(cstr[i]);
    }
}

void removeChars(std::vector<char> &vector) {
    std::remove(vector.begin(), vector.end(), '?');
    std::remove(vector.begin(), vector.end(), '!');
    std::remove(vector.begin(), vector.end(), '.');
    std::remove(vector.begin(), vector.end(), ',');
    std::remove(vector.begin(), vector.end(), ';');
    std::remove(vector.begin(), vector.end(), ':');
    std::remove(vector.begin(), vector.end(), '@');
    std::remove(vector.begin(), vector.end(), '#');
    std::remove(vector.begin(), vector.end(), '&');
    std::remove(vector.begin(), vector.end(), '"');
    std::remove(vector.begin(), vector.end(), '(');
    std::remove(vector.begin(), vector.end(), ')');
} //Removes general characters from the vector that aren't letters.

void removeSpaceChar(std::vector<char> &vector) {
    std::remove(vector.begin(), vector.end(), ' ');
} //Removes instances of the space character from the vector.

void removeAposChar(std::vector<char> &vector) {
    std::remove(vector.begin(), vector.end(), '\'');
} //Removes any instances of the apostrophe from the vector. Passes vector address to the function.

void vectorToLower(std::vector<char> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = tolower(vector[i]);
    }
} //Makes all elements of the vector lowercase if able.

void vectorToLowerCopy(std::vector<char> &vector, std::vector<char> &copy) {
    for (int i = 0; i < vector.size(); i++) {
        copy.push_back(tolower(vector[i]));
    }
} //Adds elements to a new vector but modified to be lowercase.

void sortVector(std::vector<char> &vector) {
    std::sort(vector.begin(), vector.end());
} //Sorts vector in ascending order.

void uniqueCopyTo(std::vector<char> &vector, std::vector<char> &copy) {
    std::unique_copy(vector.begin(), vector.end(), copy.begin());
} //Eliminates consecutive duplicates and copies the modified vector to a new vector without the extra chars.

void printVector(std::vector<char> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i];
    }
}
struct Equalto {
    char c;
    Equalto(char d) : c(d) {}
    bool operator()(char d) {
        return d == c;
    }
}; //Checks if a char is equal to a certain char.

bool isInVector(std::vector<char> &vector, char c) {
    return std::any_of(vector.begin(), vector.end(), Equalto(c));
} //Checks if a char is in a vector.

#endif // _VECTORS_H_