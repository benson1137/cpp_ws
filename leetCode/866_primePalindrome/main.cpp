#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

class Solution
{
public:
    int primePalindrome(int n)
    {
        // 首先确定回文数的根长度
        int initRootLength = 0;
        for (int nCopy = n; nCopy != 0; nCopy = nCopy / 10)
        {
            initRootLength++;
        }
        initRootLength = initRootLength - initRootLength / 2;
        // 从得到的根长度开始构造回文数
        for (int rootLength = initRootLength; rootLength <= 5; ++rootLength)
        {
            // 回文数长度为奇数
            for (int root = pow(10, rootLength - 1); root < pow(10, rootLength); ++root)
            {
                int constructNum = root;
                for (int rootCopy = root / 10; rootCopy != 0; rootCopy /= 10)
                {
                    constructNum = constructNum * 10 + rootCopy % 10;
                }
                if (constructNum >= n && isPrime(constructNum))
                    return constructNum;
            }
            // 回文数长度为偶数
            for (int root = pow(10, rootLength - 1); root < pow(10, rootLength); ++root)
            {
                int constructNum = root;
                for (int rootCopy = root; rootCopy != 0; rootCopy /= 10)
                {
                    constructNum = constructNum * 10 + rootCopy % 10;
                }
                // 判定是不是质数
                if (constructNum >= n && isPrime(constructNum))
                    return constructNum;
            }
        }
        return 0;
    }

    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    // vector<int> data = {111221, 101, 66, 88};
    // for (auto it = data.cbegin(); it != data.cend(); it++)
    // {
    //     cout << sln.isPalindrome(*it) << "\t"
    //          << sln.isPrime(*it) << "\t"
    //          << sln.primePalindrome(*it) << endl;
    // }
    // cout << sln.isPrime(99) << endl;
    cout << sln.primePalindrome(9989900) << endl;
    // cout << sln.primePalindrome(3) << endl;
    // cout << sln.primePalindrome(5) << endl;
    // cout << sln.isPrime(11) << endl;
    // cout << sln.isPrime(12) << endl;
    // cout << sln.isPrime(13) << endl;
    // cout << sln.isPrime(101) << endl;
    return 0;
}
