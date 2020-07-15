#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

// 向容器中添加元素
// 会改变容器大小，array不支持该操作
// 插入容器会使原本指向容器的指针、迭代器、引用失效
void add_element()
{
    // forward_list
    forward_list<int> num_flist_1 = {0, 1, 2};
    num_flist_1.push_front(255);
    num_flist_1.emplace_front(254);
    // for (auto iter = num_flist_1.cbegin(); iter != num_flist_1.cend(); iter++)
    // {
    //     cout << *iter << endl;
    // }

    // list
    list<int> num_list_1 = {0, 1, 2};
    num_list_1.push_front(255);
    // num_list_1.emplace_front(255);
    num_list_1.push_back(254);
    // num_list_1.emplace_back(254);
    // for (auto iter = num_list_1.cbegin(); iter != num_list_1.cend(); iter++)
    // {
    //     cout << *iter << endl;
    // }

    // insert的重载
    vector<int> num_list_2 = {0, 1, 2};
    // 1.在迭代器p指向的元素之前插入n个值为t的元素
    num_list_2.insert(num_list_2.cbegin(), 3, 254);
    for (auto iter = num_list_2.cbegin(); iter != num_list_2.cend(); iter++)
        cout << *iter << endl;
    cout << "------------" << endl;

    // 2.将迭代器b,e指定范围内的元素插入到迭代器p之前
    num_list_2.insert(num_list_2.cbegin(), num_list_2.cend() - 2, num_list_2.cend());
    for (auto iter = num_list_2.cbegin(); iter != num_list_2.cend(); iter++)
        cout << *iter << endl;
    cout << "------------" << endl;

    // 3.插入花括号内的元素
    num_list_2.insert(num_list_2.cbegin(), {255, 255, 255});
    for (auto iter = num_list_2.cbegin(); iter != num_list_2.cend(); iter++)
        cout << *iter << endl;
    cout << "------------" << endl;
}

void visit_element()
{
    vector<int> num_list_1 = {0, 1, 2};
    // 这三个返回的是引用
    cout << num_list_1.front() << endl;
    cout << num_list_1.back() << endl;
    cout << num_list_1.at(1) << endl;
    // 这个返回的是复制
    cout << num_list_1[1] << endl;
}

void erase_test()
{
    vector<int> num_list = {0, 1, 2, 3, 4, 5, 6, 7};
    num_list.erase(num_list.cbegin() + 1);
}

int main(int argc, char const *argv[])
{
    // add_element();
    // visit_element();
    erase_test();
}
