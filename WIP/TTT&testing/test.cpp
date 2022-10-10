#include <iostream>

using namespace std;

struct Plot {
    char NW = ' ', N = ' ', NE = ' ';
    char W = ' ', C = ' ', E = ' ';
    char SW = ' ', S = ' ', SE = ' ';
};

Plot canvas;

char Canvas[3][3] = { 
    {canvas.NW, canvas.N, canvas.NE}, 
    {canvas.W, canvas.C, canvas.E}, 
    {canvas.SW, canvas.S, canvas.SE} 
};


int main() {
    cout << Canvas[0][2];
    return 0;
}