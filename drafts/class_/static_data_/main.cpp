#include <iostream>

using namespace std;

class Point
{
private:
    static int cnt;
    int x, y;

public:
    // constructor
    Point(int x = 0, int y = 0) : x(x), y(y) { cnt++; }
    // copy constructor
    Point(Point &p)
    {
        x = p.x;
        y = p.y;
        cnt++;
    }
    static void showCnt()
    {
        cout << cnt << endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    ~Point()
    {
        cnt--;
    }
};

int Point::cnt = 0;

int main(int argc, char const *argv[])
{
    cout << "----test1----" << endl;
    Point::showCnt();
    Point p1(3, 4);
    Point p2(p1);
    Point::showCnt();
    // delete &p2;
    p2.~Point();
    Point::showCnt();

    cout << "----test2----" << endl;
    Point *pp1 = &p1;

    // // 类成员函数指针
    // int (Point::*showX)() = Point::getX;
    // // 通过成员函数指针访问
    // cout << (pp1->*showX)() << endl;
    // cout << (p1.*showX)() << endl;

    return 0;
}
