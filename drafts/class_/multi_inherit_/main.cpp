#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a = 0) : a(a) {}
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
    void setB(int b) { this->b = b; }
    int getB() const { return b; }
    ~B() {}
};

class C : public A, public B
{
private:
    int c;

public:
    C(int a = 0, int b = 0, int c = 0) : A(a), B(b), c(c) {}
    void setC(int c) { this->c = c; }
    int getC() const { return c; }
    ~C() {}
};

int main(int argc, char const *argv[])
{
    C abc(1, 2, 3);
    cout << abc.getA() << endl
         << abc.getB() << endl
         << abc.getC() << endl;
    return 0;
}
