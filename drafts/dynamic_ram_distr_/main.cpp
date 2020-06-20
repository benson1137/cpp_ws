// C/C++没有动态内存回收机制

#include <iostream>
#include <cassert>

using namespace std;

class Point
{
    friend void printPoint(const Point &p);

private:
    int x,
        y;
    static int cnt;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) { cnt++; }
    static int getCnt() { return cnt; }
    void move(int mx, int my) { x = mx, y = my; }
    int getX() const { return x; }
    int getY() const { return y; }
    ~Point() { cnt--; }
};

class ArrayOfPoints
{
private:
    Point *points;
    int size;

public:
    ArrayOfPoints(int size) : size(size) { points = new Point[size]; }
    ~ArrayOfPoints()
    {
        cout << "Deleting..." << endl;
        delete[] points;
    }
    // 这里为啥子是引用
    // 直接返回值必然是常量，例如add(1,1)返回2这种
    // 返回以后再怎么操作也跟原来的数组没关系了
    Point &element(int index)
    {
        assert(index >= 0 && index < size);
        return points[index];
    }
};

int Point::cnt = 0;

// 打印坐标 Point友元
void printPoint(const Point &p)
{
    cout << "(" << p.x << ", " << p.y << ")";
}

void dynamicArray()
{
    // 调用默认构造函数初始化
    Point *ptr = new Point[2];
    ptr[0].move(1, 2);
    ptr[1].move(3, 4);

    // 相当于只删除了ptr[0]
    // delete ptr;

    // 这里加上[]可以删除整个数组
    delete[] ptr;
}

void userDefCopyConstruc()
{
    ArrayOfPoints arr1(2);
    arr1.element(0).move(1, 2);
    arr1.element(1).move(3, 4);
    cout << "Point 1 at: ";
    printPoint(arr1.element(0));
    cout << endl;
    cout << "Point 2 at: ";
    printPoint(arr1.element(1));
    cout << endl;

    // 通过默认的拷贝构造函数初始化arr2
    // arr1与arr2数据完全一样
    ArrayOfPoints arr2(arr1);
    arr1.element(0).move(5, 6);
    arr1.element(1).move(7, 8);
    cout << "Point 1 at: ";
    printPoint(arr2.element(0));
    cout << endl;
    cout << "Point 2 at: ";
    printPoint(arr2.element(1));
    cout << endl;

    // 对应的输出结果
    // Point 1 at: (1, 2)
    // Point 2 at: (3, 4)
    // Point 1 at: (5, 6)
    // Point 2 at: (7, 8)
    // Deleting...
    // Deleting...
    // free(): double free detected in tcache 2
}

int main(int argc, char const *argv[])
{
    // // 动态地构造了一个Point对象
    // Point *p = new Point(3, 4);
    // // 回收指针指向的这部分字节
    // // 但这个指针仍然是可以访问的
    // p->move(1, 2);
    // delete p;

    // dynamicArray();
    userDefCopyConstruc();

    return 0;
}
