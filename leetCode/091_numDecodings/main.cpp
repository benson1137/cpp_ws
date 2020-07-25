#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int length = s.size();
        if (length == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        int num[length + 1];
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i <= length; ++i)
        {
            if (isDecodable(s, i - 1))
            {
                num[i] = (s[i - 1] == '0') ? num[i - 2]
                                           : num[i - 1] + num[i - 2];
                continue;
            }
            if (s[i - 1] == '0')
                return 0;
            num[i] = num[i - 1];
        }
        return num[length];
    }
    // 判断s最后两位能否解码
    bool isDecodable(string &s, int index)
    {
        int decadeDigit = s[index - 1] - 48;
        if (decadeDigit == 0 || decadeDigit > 2)
            return false;
        int unitDigit = s[index] - 48;
        int num = unitDigit + decadeDigit * 10;
        return (num <= 26) && (num > 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    string s = "100000001";
    // for (int i = 1; i < s.size(); i++)
    // {
    //     cout << sln.isDecodable(s, i) << ", ";
    // }
    // cout << endl;
    for (int i = 0; i < s.size(); i++)
    {
        string sCopy(s, 0, i + 1);
        cout << sln.numDecodings(sCopy) << ", ";
    }
    cout << endl;
    return 0;
}
