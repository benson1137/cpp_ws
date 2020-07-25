#include <iostream>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int pathNum[m][n];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    pathNum[i][j] = 1;
                    continue;
                }
                pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
            }
        }
        return pathNum[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    cout << sln.uniquePaths(3, 2) << endl;
    return 0;
}
