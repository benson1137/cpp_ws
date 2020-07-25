#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
        {
            return s;
        }
        int frontIndex = 0, backIndex = 0;
        int maxLength = 1;
        // 初始化memo
        bool isPalindrome[s.size()][s.size()];
        for (int i = 0; i < s.size() - 1; ++i)
        {
            isPalindrome[i][i] = true;
            if (s[i] == s[i + 1])
            {
                frontIndex = i;
                backIndex = i + 1;
                isPalindrome[i][i + 1] = true;
                maxLength = 2;
            }
            else
            {
                isPalindrome[i][i + 1] = false;
            }
        }
        isPalindrome[s.size() - 1][s.size() - 1] = true;

        // 回文长度循环
        for (int i = 3; i <= s.size(); ++i)
        {
            // 起始下标循环
            for (int j = 0; j + i - 1 < s.size(); ++j)
            {
                if (s[j] == s[j + i - 1] && isPalindrome[j + 1][j + i - 2])
                {
                    assert(j + 1 <= j + i - 2);
                    isPalindrome[j][j + i - 1] = true;
                    frontIndex = (maxLength < i) ? j : frontIndex;
                    backIndex = (maxLength < i) ? (j + i - 1) : backIndex;
                    maxLength = (maxLength < i) ? i : maxLength;
                }
                else
                {
                    isPalindrome[j][j + i - 1] = false;
                }
            }
        }
        return string(s.cbegin() + frontIndex, s.cbegin() + backIndex + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    string data = "aabaa";
    cout << sln.longestPalindrome(data) << endl;
    return 0;
}
