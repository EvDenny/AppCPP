#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#define __WIN32 0
using namespace std;

struct Canvas {
    int width, length;
    int area;
    vector<vector<char>> coordinates;
    Canvas(int width, int length) : width(width), length(length) {
        area = width*length;
        coordinates;
    }
    void draw();
    void swapFrame();
};

Canvas canvas(20,20);

void Canvas::draw() {
    for (int i = 0; i < canvas.length; i++) {
        for (int j = 0; j < canvas.width; j++) {
            cout << canvas.coordinates[i][j] << ' ';
        }
        cout << endl;
    }
}

void swapFrame() {
    if (__WIN32) {
        system("cls");
    } else {
        system("clear");
    }
}

struct map {
    int x, y;
    struct trail {
        char Char = '\'';
        int x, y;
    };
} map;

void newCanvas(Canvas) {
    for (int i = 0; i < canvas.length; i++) {
        for (int j = 0; j < canvas.width; j++) {
            canvas.coordinates[i][j] = '.';
        }
    }
}

class Scribe {
private:
    int x, y;
    char head = '*';
    char trail = '\'';
    Canvas canvas;
public:
    Scribe(Canvas canvas, int x = 0, int y = 0, char head = '*', char trail = '\'') : x(x), y(y), head(head), trail(trail), canvas(canvas) {
        if (x >= 0 && y >= 0 && y <= canvas.length && x <= canvas.width) {
            map.x = x; map.y = y;
            canvas.coordinates[y][x] = Scribe::head;
        } else {
            abort();
        }
    }
    
};

int main() {
    newCanvas(canvas);
    Scribe scribe(canvas);
    canvas.draw();
    return 0;
}