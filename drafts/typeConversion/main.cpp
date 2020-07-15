#include <iostream>

using namespace std;

void explicit_conversion_()
{
    // static_cast 大的数据类型转换成小的
    double a = 3.141592654;
    float ia = static_cast<float>(a);
    cout << "a is: " << a << endl
         << "ia is: " << ia << endl;

    // const_cast 常量转换为非常量
    char cc = 'a';
    // 创建一个底层const
    const char *pc = &cc;
    char *c = const_cast<char *>(pc);
    *c = 'b';
    cout << "*pc is: " << *pc << endl
         << "*c is: " << *c << endl;

    // reinterpret_cast 位模式提供较低层次的重新解释
    int i = 65;
    int *ip = &i;
    char *ipc = reinterpret_cast<char *>(ip);
    cout << "*ip is: " << *ip << endl
         << "*ipc is: " << *ipc << endl;
    // 位数据本身没有发生变化，都是0x41（int到char位数变少了）
    // 但是int被重新解释为char
}

int main(int argc, char const *argv[])
{
    explicit_conversion_();
    return 0;
}