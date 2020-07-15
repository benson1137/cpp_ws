#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

void read_only_algo()
{
    vector<int> vec = {1, 2, 44, 32, 544, 5};
    int val = 44;

    cout << "----------find------------" << endl;
    // find
    // find返回一个迭代器，指向该元素，如果不存在就指向end()
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << ((result == vec.cend()) ? "not present" : "present") << endl;
    // 迭代器可以进行+-运算
    cout << result - vec.cbegin() << endl;

    cout << endl
         << "--------accumulate-----------" << endl;
    // accumulate
    // 需要支持"+"操作
    // 最后一个形参0表示sum的初始值
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;
    // 字符串的相加
    vector<string> str_vec = {"cao", "ni", "ma"};
    string str_sum = accumulate(str_vec.cbegin(), str_vec.cend(), string(""));
    cout << str_sum << endl;

    cout << endl
         << "-----------equal---------" << endl;
    // equal
    // 判定两个序列是否保存相同的值
    vector<string> str_l1 = {"wo", "cao"};
    list<string> str_l2 = {"wo", "cao", "ni", "da", "ye"};
    // 这里应该返回true
    bool eq = equal(str_l1.cbegin(), str_l1.cend(), str_l2.cbegin());
    cout << eq << endl;
}

void write_algo()
{
    cout << "-----------fill----------" << endl;
    // fill
    vector<int> vec(10);
    // cout << algo.size() << endl;
    // 这里要写入，不能用cbegin和cend
    // 不要写入空容器
    fill(vec.begin(), vec.end(), 10);
    for (int i : vec)
        cout << i << "\t";
    cout << endl;

    // 写入的数量需要自行控制
    fill_n(vec.begin(), vec.size(), 1);
    // fill_n(vec.begin(), 10, 1);
    for (int i : vec)
        cout << i << "\t";
    cout << endl;

    cout << endl
         << "-----------back_inserter------------" << endl;
    // back_inserter
    vector<int> blank_vec;
    auto it = back_inserter(blank_vec);
    *it = 22;
    for (int i : blank_vec)
        cout << i << "\t";
    cout << endl;
    // 再插入10个值
    fill_n(it, 10, 2);
    // for (int i : blank_vec)
    //     cout << i << "\t";
    // cout << endl;

    cout << endl
         << "------------copy-------------" << endl;
    // copy
    int array1[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int array2[sizeof(array1) / sizeof(*array1)];
    auto ret = copy(begin(array1), end(array1), array2);
    for (int i : array2)
        cout << i << "\t";
    cout << endl;

    cout << endl
         << "-------------replace-----------" << endl;
    // replace
    string str1 = "asnsksmslsmsls";
    replace(str1.begin(), str1.end(), 's', 'n');
    cout << str1 << endl;
}

void rearrange_algo()
{
    cout << endl
         << "--------sort------------" << endl;
    // sort
    vector<string> vec = {"fox", "jumps", "over", "quick", "red", "slow", "the", "turtle"};
    // 按字典排序
    sort(vec.begin(), vec.end());

    for (auto i : vec)
        cout << i << "\t";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // read_only_algo();
    // write_algo();
    rearrange_algo();
    return 0;
}
