#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "point.h"

// public 继承

// class Rectangle : public Point
// {
// private:
//     float w, h;

// public:
//     Rectangle() { cnt++; }

//     void initRectangle(float x, float y, float w, float h)
//     {
//         // 基类的private成员无法直接访问
//         initPoint(x, y);
//         this->w = w;
//         this->h = h;
//     }

//     float getH() const { return h; }
//     float getW() const { return w; }
//     ~Rectangle() { cnt--; }
// };

// private 继承

class Rectangle : private Point
{
private:
    float w, h;

public:
    Rectangle() {}

    void initRectangle(float x, float y, float w, float h)
    {
        // 基类的private成员无法直接访问
        Point::initPoint(x, y);
        this->w = w;
        this->h = h;
    }
    float getX() const { return Point::getX(); }
    float getY() const { return Point::getY(); }
    float getH() const { return h; }
    float getW() const { return w; }
    ~Rectangle() {}
};
#endif