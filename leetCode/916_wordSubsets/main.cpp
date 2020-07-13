#include <iostream>
#include <vector>
#include <string>
// #include "violent.hpp"
// #include "hashTabSln.hpp"
// #include "hashTab++.hpp"

using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        // 把B整合成一个哈希表
        vector<int> BTable(26, 0);
        for (string s : B)
        {
            // 处理B中单个元素的哈希表
            vector<int> elemTable(26, 0);
            for (int i = 0; i < s.size(); i++)
            {
                elemTable[s[i] - 'a']++;
                BTable[s[i] - 'a'] = max(BTable[s[i] - 'a'], elemTable[s[i] - 'a']);
            }
        }
        // 对A进行判断
        vector<string> res;
        for (int i = 0; i < A.size(); i++)
        {
            vector<int> AElemTable(26, 0);
            // 计算A[i]
            for (int c : A[i])
            {
                AElemTable[c - 97]++;
            }
            // 判断A[i]
            int j = 0;
            for (; j < 26; j++)
            {
                if (BTable[j] > AElemTable[j])
                {
                    break;
                }
            }
            if (j == 26)
            {
                res.push_back(A[i]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    vector<string> A = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> B = {"e", "o"};
    vector<string> res = sln.wordSubsets(A, B);
    for (auto i : res)
    {
        cout << i << endl;
    }
    // cout << sln.isWordSubset("ababc", "ac") << endl;
    return 0;
}
