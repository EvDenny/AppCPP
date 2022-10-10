#define _LIBCPP_STRING_H_HAS_CONST_OVERLOADS
#define _LIBCPP_PREFERRED_OVERLOAD
#define _LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <assert.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

class Random {
public:
    Random() {}
    int operator()(int a, int b);
    double operator()(double a, double b);
};

class RNG {
protected:
    vector<int> valuesI;
    vector<double> valuesD;
    int x;
    double y;
public:
    RNG(int x = 0, double y = 0.0) : x(x), y(y) {
        cout << "int Vector capacity: " << valuesI.capacity() << endl;
        cout << "double Vector capacity: " << valuesD.capacity() << endl;
    }
    void displayMenu();
    inline int genInteger(int a, int b) { Random integer; int x = integer(a, b); return x; }
    inline double genDouble(double a, double b) { Random decimal; double x = decimal(a, b); return x; }
    int customIntRange();
    double customDoubleRange();
    inline int getInt() { return x; }
    inline double getDouble() { return y; }
    inline void setInt(int value) { x = value; }
    inline void setDouble(double value) { y = value; }
};

class Filer : public RNG {
protected:
    vector<int> valuesI;
    vector<double> valuesD;
    int x;
    double y;
public:
    Filer() {
        this->x = x;
        this->y = y;
        this->valuesI = valuesI;
        this->valuesD = valuesD;
    };
    bool openFile(string fileName) {
        fstream filer;
        filer.open(fileName, _S_app);
        bool done = false;
        while (!done) {
            cout << "(1) to write vectorInt to file. (2) to write vectorDouble to file." << endl;
            cout << "-> ";
            int input;
            filer.close();
            cin >> input;
            switch (input) {
                case 1:
                    break;
                case 2:
                    // writeDoubleVector();
                    break;
                default:
                    cout << "Invalid selection." << endl;
                    break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            }
        }
        filer.close();
        cout << "File Closed." << endl;
        bool closed = true;
        return closed;
    }
    void writeIntVector(fstream fileHandler);
    void writeDoubleVector();
    void appendvI(int a) {
        valuesI.push_back(a);
    }
};


void VectorProgram();

void newProgram() {
    system("cls");
    cout << "Choose new program to run: " << endl;
    cout << "1. Printing Vector of Ints " << endl;
    cout << "-> ";
    string input;
    getline(cin, input);
    if (input == "1") {
        VectorProgram();
    }
}

Filer FILES;

int main() {
    newProgram();
    return 0;
};

int Random::operator()(int a, int b) {
        std::random_device rd;
        std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd()};
        std::mt19937 eng = std::mt19937(seed);
        std::uniform_int_distribution<int> dist(a, b);
        return dist(eng);
    }  

double Random::operator()(double a, double b) {    
        std::random_device rd;
        std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd()};
        std::mt19937 eng = std::mt19937(seed);
        std::uniform_real_distribution<double> dist(a, b);
        return dist(eng);
    }

void Filer::writeIntVector(fstream fileHandler) {
    int items = valuesI.size();
    for (int i = 0; i < items; i++) {
        const char* a = (const char*)valuesI[i];
        fileHandler.write(a, 3);
    }
}

void VectorProgram() {
    system("cls");
    cout << "Add numbers to vector. Continue..." << endl;
    cin.get();
    vector<int> numbers;
    Random rander;
    for (int i = 0; i < 20; i++) {
        numbers.push_back(rander(1,100));
    }
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    fstream filer;
    filer.open("file.txt", _S_app);
    int items = numbers.size();
    string array[20];
    for (int i = 0; i < items; i++) {
        array[i] = numbers[i];
    }
    vector<char> writer;
    for (int i = 0;, i < 20; i++) {
        if (array[i] == (char[1]){}) {
            strchr(array[i]);
        }
    }
    filer.write('\n');
    filer.close();
}