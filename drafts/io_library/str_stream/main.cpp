#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

void test_istrstrm()
{
    // 创建文件流
    ifstream in("infile.txt");
    // 读取数据
    string line, word;
    vector<PersonInfo> people;

    // 从文件流中获取一行
    while (getline(in, line))
    {
        PersonInfo info;
        // 创建string流关联到line
        istringstream record(line);
        // 读取名字（这里只会读取空格之前的一个单词）
        record >> info.name;
        // 读取剩下的单词
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    // 重新输出内容
    for (const PersonInfo &item : people)
    {
        cout << item.name << endl;
        for (string num : item.phones)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    test_istrstrm();
    return 0;
}
