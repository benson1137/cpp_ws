#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a = 0) : a(a) {}
    A(const A &a) { this->a = a.a; }
    void setA(int a) { this->a = a; }
    int getA() const { return a; }
    ~A() {}
};

class B
{
private:
    int b;

public:
    B(int b = 0) : b(b) {}
    B(const B &b) { this->b = b.b; }
    void setB(int b) { this->b = b; }
    int getB() const { return b; }
    ~B() {}
};

// 如果可以避免，就不要使用多个基类
class C : public A, public B
{
private:
    int c;

public:
    // 构造函数的调用顺序是继承的顺序
    C(int a = 0, int b = 0, int c = 0) : A(a), B(b), c(c) {}
    C(const C &c) : A(c), B(c) { this->c = c.c; }
    void setC(int c) { this->c = c; }
    int getC() const { return c; }
    // 析构函数的调用次序与构造函数相反
    ~C() {}
};

int main(int argc, char const *argv[])
{
    C abc(1, 2, 3);
    cout << abc.getA() << endl
         << abc.getB() << endl
         << abc.getC() << endl;

    // 调用拷贝构造函数
    C cba(abc);
    cout << cba.getA() << endl
         << cba.getB() << endl
         << cba.getC() << endl;
    return 0;
}
