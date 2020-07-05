#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 自顶向下的递归解法
int LCSFromTop(vector<int> &X, vector<int> &Y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (X[m - 1] == Y[n - 1])
    {
        return LCSFromTop(X, Y, m - 1, n - 1) + 1;
    }
    else
    {
        return max(LCSFromTop(X, Y, m, n - 1), LCSFromTop(X, Y, m - 1, n));
    }
}

// 动态规划
int LCSFromBottom(vector<int> &X, vector<int> &Y, int m, int n)
{
    int length[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        length[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        length[0][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[m - 1] == Y[n - 1])
            {
                length[i][j] = length[i - 1][j - 1] + 1;
            }
            else
            {
                length[i][j] = max(length[i - 1][j], length[i][j - 1]);
            }
        }
    }
    return length[m][n];
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 2, 3, 4, 6, 7, 8, 9};
    vector<int> v2 = {1, 3, 4, 9, 7, 7, 8};
    // 自顶向下递归
    // cout << LCSFromTop(v1, v2, v1.size(), v2.size()) << endl;
    // 自底向上 动态规划
    cout << LCSFromTop(v1, v2, v1.size(), v2.size()) << endl;
    return 0;
}
