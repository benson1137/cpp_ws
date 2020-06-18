// C/C++没有动态内存回收机制

#include <iostream>

class Point
{
private:
    int x, y;
    static int cnt;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) { cnt++; }
    static int getCnt() { return cnt; }
    void move(int mx, int my) { x = mx, y = my; }
    int getX() const { return x; }
    int getY() const { return y; }
    ~Point() { cnt--; }
};

int Point::cnt = 0;

void dynamicArray()
{
    Point *ptr = new Point[2];
    ptr[0].move(1, 2);
    ptr[1].move(3, 4);

    // 相当于只删除了ptr[0]
    // delete ptr;

    // 这里加上[]可以删除整个数组
    delete[] ptr;
}

int main(int argc, char const *argv[])
{
    // // 动态地构造了一个Point对象
    // Point *p = new Point(3, 4);
    // // 回收指针指向的这部分字节
    // // 但这个指针仍然是可以访问的
    // p->move(1, 2);
    // delete p;

    dynamicArray();

    return 0;
}
