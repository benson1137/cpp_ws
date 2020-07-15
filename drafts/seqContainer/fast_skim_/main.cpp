#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

void initialization_test()
{
    // 直接初始化
    vector<string> authors = {"Milton", "Shakespeare", "Austen"};
    list<string> authors_list = {"Milton", "Shakespeare", "Austen"};
    vector<string> authors_1;
    // array初始化时必须指定大小
    array<string, 3> authors_array = {"Milton", "Shakespeare", "Austen"};
    array<string, 3> authors_array_1;
    array<int, 3> number_array;

    // 花括号赋值
    authors_1 = {"Milton", "Shakespeare"};
    authors_array_1 = {"Milton", "Shakespeare"};
    // number_array的size为3，赋值后最后一位变成0
    number_array = {0, 1};

    // 利用迭代器进行切片初始化
    vector<string> authors_slice(authors.begin() + 1, authors.end());
    // list这里不支持对迭代器进行加减
    // 那么这个操作没有意义
    // list<string> authors_list_slice(authors_list.begin(), authors_list.end());

    // 这里输出的结果是cxx17__normal_iterator
    auto it = authors_slice.cbegin();
    cout << typeid(it).name() << endl;

    // vector输出
    for (auto it = authors_slice.cbegin(); it != authors_slice.cend(); it++)
    {
        cout << *it << endl;
    }
    cout << "------" << endl;
    for (auto it = authors_array.cbegin(); it != authors_array.cend(); it++)
    {
        cout << *it << endl;
    }
    cout << "------" << endl;
    for (auto it = number_array.cbegin(); it != number_array.cend(); it++)
    {
        cout << *it << endl;
    }

    // list输出
    // for (auto iter = authors_list_slice.cbegin(); iter != authors_list_slice.cend(); iter++)
    // {
    //     cout << *iter << endl;
    // }
}

void assign_test()
{
    // array不支持assign

    // 直接初始化
    vector<string> authors = {"Milton", "Shakespeare", "Austen"};
    list<string> authors_list = {"Milton", "Shakespeare", "Austen"};

    // 切片赋值
    vector<string> authors_slice;
    authors_slice.assign(authors.cbegin() + 1, authors.cend());
    for (auto iter = authors_slice.cbegin(); iter != authors_slice.cend(); iter++)
    {
        cout << *iter << endl;
    }
    // cout << "--------" << endl;

    // list测试
    // list<string> authors_list_slice;
    // list这里迭代器不支持加减
    // authors_list_slice.assign(authors_list.cbegin(), authors_list.cend());
    // for (auto iter = authors_list_slice.cbegin(); iter != authors_list_slice.cend(); iter++)
    // {
    //     cout << *iter << endl;
    // }
}

// swap 交换相同类型两个容器中的内容
void swap_test()
{
    // 直接初始化
    list<string> authors_1 = {"Milton", "Shakespeare", "Austen"};
    list<string> authors_2 = {"NotliM", "Netsua"};

    authors_1.swap(authors_2);
    // 等价操作
    // swap(authors_2, authors_1);

    for (auto iter = authors_1.cbegin(); iter != authors_1.cend(); iter++)
    {
        cout << *iter << endl;
    }
    cout << "---------" << endl;
    for (auto iter = authors_2.cbegin(); iter != authors_2.cend(); iter++)
    {
        cout << *iter << endl;
    }
}

int main(int argc, char const *argv[])
{
    initialization_test();
    // assign_test();
    // swap_test();
}
