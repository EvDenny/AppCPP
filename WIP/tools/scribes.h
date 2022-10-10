#ifndef __SCRIBES_H__
#define __SCRIBES_H__

class Random {
public:
    Random() {};
};

class Canvas {
private:
    int x, y, total;
    pair position;
    std::vector<Scribe scribes> scribes;
public:
    Canvas(int X, int Y) : x(X), y(Y);
    void create();
    void addScribe(Scribe scribe);
    void setScribe();
    void addTrail();
    void draw();
};

class Scribe {
private:
    Canvas canvas;
    std::pair<int, int> position;
    int x, y;
    float angle;
    char self = '*';
    char trail = '\'';
    bool moved = false;
public:
    Scribe(Canvas canvas, int x, int y, float angle = 135.f, char self = '*', char trail = '\'') : x( ), y(y), angle(angle), self(self), trail(trail);
    inline void setPosition() { canvas.setScribe(); }
    void mark();
    void move();
};

#endif // __SCRIBES_H__