#include <iostream>
#include <string>
#include <exception>
// 关联容器
#include <set>
#include <map>

using namespace std;

// 集合：有序、无重复
void setTest()
{
    int num;
    set<int> s;
    while (cin >> num)
    {
        if (num == 0)
            break;
        s.insert(num);
    }
    for (int i : s)
        cout << i << "\t";
    cout << endl;
}

// 映射：有序
void mapTest1()
{
    map<string, string> dict;
    dict.insert(make_pair("math", "math is hard"));
    dict.insert(make_pair("physics", "physics is much harder than math"));
    dict.insert(make_pair("biology", "i don't understand"));
    string key;
    cin >> key;
    map<string, string>::iterator iter = dict.find(key);
    if (iter == dict.cend())
    {
        cout << "not found" << endl;
        return;
    }
    cout << iter->second << endl;
}
void mapTest2()
{
    map<string, string> dict;
    dict.insert(make_pair("math", "math is hard"));
    dict.insert(make_pair("physics", "physics is much harder than math"));
    dict.insert(make_pair("biology", "i don't understand"));
    // 支持类似Python的元素插入方式
    dict["chemistry"] = "????????";
    for (auto key : dict)
    {
        cout << key.first << " : " << key.second << endl;
    }

    string key;
    cin >> key;
    // 支持[]操作符
    cout << dict[key] << endl;
}

// 多重映射
void multiMapTest()
{
    // 多重映射不支持索引初始化
    typedef multimap<string, string>::iterator functionIter;
    multimap<string, string> mmp;
    mmp.insert(make_pair("home", "forward"));
    mmp.insert(make_pair("home", "speed=0"));
    mmp.insert(make_pair("end", "backward"));
    mmp.insert(make_pair("insert", "speedup"));
    mmp.insert(make_pair("insert", "speed+=10"));

    string keyword = "";
    do
    {
        cin >> keyword;
    } while (mmp.count(keyword) == 0);

    pair<functionIter, functionIter> res = mmp.equal_range(keyword);
    for (functionIter it = res.first; it != res.second; it++)
    {
        cout << it->second << endl;
    }
}

int main(int argc, char const *argv[])
{
    // setTest();
    // mapTest1();
    // mapTest2();
    multiMapTest();
    return 0;
}
