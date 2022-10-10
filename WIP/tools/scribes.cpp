#include <iostream>
#include <string>
#include <random>
using namespace std;

Random::Random() {
    auto operator()(int a, int b) {
        std::random_device rd;
        std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd() };
        std::mt19937 eng = std::mt19937(seed);
        std::uniform_int_distribution<int> dist(a, b);
        return dist(eng);
    }
}

Canvas::Canvas(int X, int Y) : x(X), y(Y) {
    total = x*y;
    struct dimensions {
        int ymin = 0;
        int xmin = 0;
        int ymax = y;
        int xmax = x;
    };
}

void Canvas::create() {
    char xA[x];
    char yA[y];
    for (int i = 0; i < x; i++) {
        xA[i].append(' ');
    }
    for (int i = 0; i < y; i++) {
        yA[i].append(xA[]);
    }
}

    void addScribe(Scribe scribe) {
        scribes.append(scribe);
    }

void Canvas::setScribe() {
    if (scribe[0].origin.x > Canvas::dimensions.xmin && scribes[0].origin.x < Canvas::dimensions.xmax) {
        if (scribe[0].origin.y > Canvas::dimensons.ymin && scribes[0].origin.y < Canvas::dimensions.ymax) {
            Scribe::origin.y = yA[Scribe::origin.y];
            Scribe::origin.x = xA[Scribe::origin.x];
            Scribe::origin.position = std::make_pair<int x, int y>(int && origin.x, int && origin.y);
        } else {
            cout << "Please set new (x,y) coordinates for Scribe. Invalid coordinates selected." << endl;
            exit(0);
        }
    } else {
        cout << "Please set new (x,y) coordinates for Scribe. Invalid coordinates selected." << endl;
        exit(0);
    }
}

void Canvas::addTrail() {
    for (int i = 0; i < Scribe::marks.yArray.size(); i++) {
        // for (yA[Scribe::marks.yArray[i]]) {
        //     xA[Scribe::marks.xArray[i]] = '.';
        // }
        xA.at(Scribe::marks.xArray[i]) in yA.at(Scribe::marks.yArray[i]) = '.';
    }
}

void Canvas::draw() {
    for (int i = 0, i < yA.size(); i++) {
        for (int j = 0; j < xA.size(); j++) {
            if (xA[j] == )
            cout << xA[j] << ' ';
        }
    }
}

Scribe::Scribe(Canvas canvas, int x, int y, float angle = 135.f, char self = '*', char trail = '\'') : x( ), y(y), angle(angle), self(self), trail(trail) {
    position = ::make_pair<int, int>(int && x, int && y);
    struct origin {
        Canvas canvas = canvas; // Sets binding of scribe to existing canvas object.
        int x, y = x, y; // Sets (x,y) coordinates for scribe's origin position on the Canvas. Should make default 0,0.
        pair<int x, int y> position = position; // Origin position in case needed in future class functions.
        float angle = angle; // Angle the scribe is facing of total 360 degrees
        char self = self; // Sets drawn position character.
    };
    struct marks {
        char currentX = origin.x, currentY origin.y;
        char xArray[];
        char yArray[];
    };
}

void Scribe::mark() {
    if (move) {
        Scribe::marks.xArray.append(Scribe::marks.currentX);
        Scribe::marks.yArray.append(Scribe::marks.currentY);
        
    }
}

void Scribe::move() {
    
    move = true;
}

Canvas canvas1(20, 20);
canvas1.create();
Scribe scribe1(canvas1, 10, 10, 90.f, '*', '\'');
scribe1.setPosition();