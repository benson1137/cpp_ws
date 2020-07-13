#pragma once

// 暴力解法：超时

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &A, std::vector<std::string> &B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                if (!isWordSubset(A[j], B[i]))
                {
                    A.erase(A.begin() + j);
                    j--;
                }
            }
        }
        return A;
    }
    bool isWordSubset(std::string str, std::string sub)
    {
        if (sub.size() > str.size())
            return false;
        for (int i = 0; i < sub.size(); i++)
        {
            int strSize = str.size();
            for (int j = 0; j < strSize; j++)
            {
                if (str[j] == sub[i])
                {
                    str.erase(str.cbegin() + j);
                    break;
                }
            }
            if (str.size() == strSize)
            {
                return false;
            }
        }
        return true;
    }
};
