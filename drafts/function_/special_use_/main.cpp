#include <iostream>
#include <cassert>
#include <string>

// 如果NDEBUG被定义，则assert什么也不做
#define NDEBUG

using namespace std;

// 默认参数
void print(int a, int b = 1, string s = "s")
{
    cout << a << b << s << endl;
}

// 内联函数
// 在编译过程中展开，避免函数调用的开销
// inline const string &shorterString(const string &s1, const string &s2)
inline const string &shorterString(const string &s1, const string &s2)
{
    return (s1.size() <= s2.size()) ? s1 : s2;
}

// constexpr函数
// 所有形参以及返回值的类型必须为字面值
// 函数体中必须只能有一条return语句
// constexpr被隐式地指定为内联函数
constexpr int bigger(int x, int y)
{
    return (x >= y) ? x : y;
}

int main(int argc, char const *argv[])
{
    print(1);
    print(1, 2);

    cout << shorterString("12", "1231") << endl;
    int a = 1, b = 2;
    // 这里返回的已经不是constexpr了
    cout << bigger(a, b) << endl;

    // a,b是变量，但编译能通过，
    // int t[bigger(a, b)];

    // 传入字面值，这是constexpr
    int t[bigger(1, 2)];

    t[0] = 123;
    cout << t[0] << endl;

    // 如果给bigger()传入的是变量，这里编译无法通过
    cout << end(t) - begin(t) << endl;

    // 调试帮助
    // assert 检查条件不满足的情况
    int e = 11;
    assert(e > 10);

    return 0;
}
