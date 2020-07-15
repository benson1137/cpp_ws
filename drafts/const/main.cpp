#include <iostream>
#include <vector>

using namespace std;

// const的引用
void const_ref()
{
    int i = 42;
    // 非常量引用
    int &ri = i;
    // 常量引用
    const int &ci = i;

    cout << "ri is: " << ri << "\tci is: " << ci << endl;

    // 通过常量引用修改值
    ri = 41;
    cout << "ri is: " << ri << "\tci is: " << ci << endl;

    // 用ci修改i的值是非法操作
    // ci = 41;
    // cout << "ri is: " << ri << "\tci is: " << ci << endl;

    // 这是一个常量引用
    const int &r1 = i * 2;
    cout << "r1 is: " << r1 << endl;

    // 修改再次修改i的值
    ri = 40;
    cout << "r1 is: " << r1 << endl;
    // r1的值没有变化，常量引用
}

// const与指针
void const_primer()
{
    int i = 1;
    // 指针pi将一直指向i（指针本身的值不变）
    int *const pi = &i;
    // 指针ci一直指向i，且不能通过*ci修改i
    const int *const ci = &i;
    i = 2;
    cout << "*pi is: " << *pi << "\tci is: " << *ci << endl;

    // 改变*pi的值
    *pi = 3;
    cout << "*pi is: " << *pi << "\tci is: " << *ci << endl;

    // 改变*ci的值是非法操作
    // *ci = 4;
    // cout << "*pi is: " << *pi << "\tci is: " << *ci << endl;
}

void ref_function(const vector<int> &a)
{
    // a.push_back(0);
    for (auto i : a)
        cout << i << "\t";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // const_ref();
    // const_primer();

    vector<int> data = {1, 2, 3, 4, 5, 6};
    ref_function(data);
    return 0;
}
