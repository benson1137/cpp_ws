#include <iostream>

using namespace std;

// 常量引用与指针
void const_ref_ptr()
{
    float i = 42;
    // 不能通过r1修改i的值
    const float &r1 = i;
    // 不能通过*p修改i的值
    const float *p = &i;
    // 可以修改i改变r1和*p的值
    i = 2;
    // p的值可以修改，从而*p的值也被修改
    p++;
    cout << i << endl;
    cout << r1 << endl;
    cout << *p << endl;
    // cout << typeid(i).name() << endl;
    // cout << typeid(r1).name() << endl;
}

// 常量指针
void const_ptr()
{
    int i = 11;
    // p本身的值不能被改变，但其指向的值可以被改变
    int *const p = &i;

    const double pi = 3.1415;
    // pip是一个指向常量的常量指针
    const double *const pip = &pi;
}

int main(int argc, char const *argv[])
{
    const_ref_ptr();
    return 0;
}
