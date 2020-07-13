#pragma once

// B整合成一个哈希表：超时

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &A, std::vector<std::string> &B)
    {
        std::vector<int> subTable = BtoHashTab(B);
        for (int i = 0; i < A.size(); i++)
        {
            std::vector<int> strTable(26, 0);
            // 计算A[i]的哈希表
            for (int c : A[i])
            {
                strTable[c - 97]++;
            }
            // 判断A[i]
            if (!isWordSubset(strTable, subTable))
            {
                // A.erase(A.begin() + i);
                A[i] = "";
                // i--;
            }
        }
        // return A;
        std::vector<std::string> res;
        for (std::string &s : A)
        {
            if (s != "")
            {
                res.push_back(s);
            }
        }
        return res;
    }
    bool isWordSubset(std::vector<int> &strTable, std::vector<int> &subTable)
    {
        for (int i = 0; i < 26; i++)
        {
            if (subTable[i] > strTable[i])
            {
                return false;
            }
        }
        return true;
    }
    std::vector<int> BtoHashTab(std::vector<std::string> &B)
    {
        std::vector<int> totalTable(26, 0);
        for (std::string s : B)
        {
            // 处理B中每一个元素的哈希表
            std::vector<int> elemTable(26, 0);
            for (int c : s)
            {
                elemTable[c - 97]++;
            }
            for (int i = 0; i < 26; i++)
            {
                totalTable[i] = std::max(totalTable[i], elemTable[i]);
            }
        }
        return totalTable;
    }
};
