#include <iostream>
#include <string>
#include <vector>

using namespace std;

void use_of_iterator()
{
    vector<int> a(10, 0);
    auto b = a.begin();
    cout << typeid(b).name() << endl;
    // b的类型是一个iterator

    // 迭代器的泛型编程
    // 标准库中所有的容器都定义了!=与==，但是大多数不支持<
    for (auto i = a.begin(); i != a.end(); i++)
    {
        // 任何使用迭代器的循环体，都不要向迭代器所属的容器中添加元素
        // 迭代器失效，引发Segment Fault
        // a.push_back(1);
        cout << *i << endl;
    }
}

int main(int argc, char const *argv[])
{
    use_of_iterator();
    return 0;
}
