#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 044 通配符匹配
// s：字符串，只包含a-z
// p：字符模式，包含a-z以及?、*

vector<int> getNext(const string &s)
{
    int i = 1, j = 0;
    int maxSize = s.size();
    vector<int> nextIndex(maxSize, 0);
    nextIndex[i] = j;
    while (i < maxSize)
    {
        if (j == 0 || s[i] == s[j])
        {
            j++;
            i++;
            nextIndex[i] = (s[i] == s[j]) ? nextIndex[j] : j;
        }
        else
        {
            j = nextIndex[j];
        }
    }
    return nextIndex;
}

// 无法使用长度判定，*的长度可以为0
bool isMatch(string s, string p)
{
    // KMP匹配
    // 对p使用next函数？
    return false;
}

int main(int argc, char const *argv[])
{
    string data = "abc?abcd";
    vector<int> nextIndex = getNext(data);
    for (int i : nextIndex)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
