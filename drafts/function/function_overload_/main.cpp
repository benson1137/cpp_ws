#include <iostream>
#include <string>
using namespace std;

void print(int a)
{
    cout << "param type is int" << endl;
}

void print(char c)
{
    cout << "param type is char" << endl;
}

void print(float n)
{
    cout << "param type is float" << endl;
}

void print(string s)
{
    cout << "param type is string" << endl;
}

int main(int argc, char const *argv[])
{
    // 正常，string不能转换成别的
    print("ad");

    // 报错，会找到超过一个匹配的重载函数
    // float char int之间可以相互转换
    // print(3.14);
}
