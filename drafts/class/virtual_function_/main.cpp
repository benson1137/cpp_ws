#include <iostream>

using namespace std;

class Base1
{
private:
    int a;

public:
    Base1(int a = 0) : a(a) {}

    // 使用虚函数
    // 避免在编译时就给指针绑定函数，而是在运行时绑定
    virtual void display() const
    {
        cout << "Base1::display " << a << endl;
    }
    int getA() const { return a; }
    virtual ~Base1() {}
};

class Base2 : public Base1
{
private:
    int b;

public:
    Base2(int b = 0) : b(b) {}

    virtual void display() const
    {
        cout << "Base2::display " << b << endl;
    }
    int getB() const { return b; }
    virtual ~Base2() {}
};

void func(Base1 *p)
{
    p->display();
}

int main(int argc, char const *argv[])
{
    // 如果不使用虚函数，则在编译时进行绑定
    // 由于func形参类型是Base1，因此b2将被转换成Base1指针
    // 编译时给b2绑定的display函数为Base1::display()
    // 若使用虚函数，则在运行时绑定
    // b2使用的display函数将由b2指针指向的具体对象决定
    Base1 b1(1);
    Base2 b2(2);
    func(&b1);
    func(&b2);

    // 虚析构函数
    Base1 *p1 = new Base2;
    // 这里调用谁的析构函数
    delete p1;
}
