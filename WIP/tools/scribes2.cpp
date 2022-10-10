#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

struct canvas {
    int length;
    int width;
    std::vector<std::vector<char>> coordinates;
};

struct currentScribe {
    int x, y;
    std::tuple<int, int> Pos = (x, y);
};

class Canvas {
private:
    int l, w;
    int total;
    std::vector<std::vector<char>> coordinates;
public:
    Canvas(int length, int width) : l(length), w(width) {
        total = w*l;
        for (int j = 0; j < l; j++) {    
            for (int i = 0; i < w; i++) {
                coordinates[j].pushback(' ');
            }
        }
    }
    void print();
    void listen();
};

class Mapping : public Canvas {
private:
    Canvas canvas;
    int broadcastID;
    int x, y;
public:
    Mapping(Canvas canvas, int x, int y) : canvas(canvas), x(x), y(y) {
        // Origin point for any scribe to map trail
        if (x < Canvas::width && x > 0 && y > 0 && y < Canvas::length) {
            Canvas::coordinates[y[x]] = '*';
        }
    }
    inline void setBroadcastID(int id) { broadcastID = id; }
    void update();
    void addTrail();
    void setPos();
    void broadcast();
};

class Scribe : public Canvas {
private:
    Canvas canvas;
    int broadcastID;
    char head = '*', trail = '\'';
    std::tuple<int, int> Pos = (x, y);
    int x, y;
public:
    Scribe(Canvas canvas, int x = 0, int y = 0, char head = '*', char trail = '\'') : canvas(canvas), x(x), y(y), head(head), trail(trail) {
        Pos = (x, y);
        map(x, y);
        broadcastID;
    }
    inline void setBroadcastID(int id) { broadcastID = id; }
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline void setXY(int a, int b) { x = a; y = b; }
    void up();
    void down();
    void left();
    void right();
    void broadcast();
};

class Multiplex {
private:
    int id;
    std::vector<int> channels;
    bool diff;
    bool fix;
public:
    Multiplex(int id, bool diff = true, bool fix = false) : id(id), diff(diff), fix(fix) {
        channels.pushback(0xa0);
        channels.pushback(0xa1);
    }
};

class Channel : public Multiplex {
private:
    int channel;
    bool ean;
    bool re;
    int broadcast;
public:
    Channel(int channel, bool ean, bool re) : channel(channel), ean(ean), re(re) {
        broadcast;
    }
    inline void setBroadcast(int id) { broadcast = id; }
};

int main() {
    Canvas frame(20,20);
    Mapping map(frame, 20, 20);
    Scribe scribe(frame);
    return 0;
}

void Scribe::up() {
    int b = Scribe::getY() - 1;
    Scribe::setXY(x, b);
    Pos = (getX(), getY());
}