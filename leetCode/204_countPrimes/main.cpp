#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 筛选法
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        int cnt = 0;
        vector<bool> primeTable(n, true);
        primeTable[0] = false;
        primeTable[1] = false;
        for (int facorIndex = 2; facorIndex * facorIndex < n; facorIndex++)
        {
            if (!primeTable[facorIndex])
                continue;
            for (int cursorIndex = facorIndex * facorIndex; cursorIndex < n; cursorIndex += facorIndex)
            {
                primeTable[cursorIndex] = false;
                cnt++;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     (primeTable[i]) ? cnt++ : cnt;
        // }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    cout << sln.countPrimes(10) << endl;
    return 0;
}
