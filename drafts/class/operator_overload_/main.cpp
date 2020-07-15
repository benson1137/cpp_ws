#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a = 0) : a(a) {}
    int getA() const { return a; }
    // 单目运算符，分前置(++i)后置(i++)
    // 前置操作要求返回引用，先自增再返回，返回值要求可以作为左值使用
    A &operator++();
    // 后置操作要求返回的是副本
    A operator++(int i);

    // 双目运算符
    A operator+(const A &a_) const { return A(a + a_.a); }

    // 重载为非成员函数
    friend ostream &operator<<(ostream &out, const A &a);

    ~A() {}
};

// 前置++
A &A::operator++()
{
    a++;
    // 返回的是当前对象自身;
    return *this;
}

// 后置++
A A::operator++(int i)
{
    A old = *this;
    ++(*this);
    return old;
}

// 重载为非成员函数
ostream &operator<<(ostream &out, const A &a)
{
    out << a.a;
    return out;
}

int main(int argc, char const *argv[])
{
    A a1(3);
    A a2(4);
    A a3 = a1 + a2;
    cout << a3.getA() << endl;
    return 0;
}
