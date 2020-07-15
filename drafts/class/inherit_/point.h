#ifndef _POINT_H_
#define _POINT_H_

class Point
{
    friend void showPoint(Point &p);

private:
    float x, y;

public:
    // constructor
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    void initPoint(float x, float y) { this->x = x, this->y = y; }

    void move(int mx, int my) { x = mx, y = my; }
    static int getCnt() {}
    float getX() const { return x; }
    float getY() const { return y; }
    ~Point() {}
};

void showPoint(Point &p);

#endif