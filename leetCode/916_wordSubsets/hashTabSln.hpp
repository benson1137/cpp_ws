#pragma once

// 哈希表解法：超时

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &A, std::vector<std::string> &B)
    {
        for (int i = 0; i < A.size(); i++)
        {
            std::vector<int> strTable(26, 0);
            // 计算A[i]的哈希表
            for (int c : A[i])
            {
                strTable[c - 97]++;
            }
            for (int j = 0; j < B.size(); j++)
            {
                if (!isWordSubset(strTable, B[j]))
                {
                    A.erase(A.begin() + i);
                    i--;
                    break;
                }
            }
        }
        return A;
    }
    bool isWordSubset(std::vector<int> strTable, std::string sub)
    {
        std::vector<int> subTable(26, 0);
        for (int c : sub)
        {
            subTable[c - 97]++;
            if (subTable[c - 97] > strTable[c - 97])
            {
                return false;
            }
        }
        return true;
    }
};
