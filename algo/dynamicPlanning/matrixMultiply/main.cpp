#include <iostream>
#include <vector>

using namespace std;

// 自顶向下
// 效率低下
int chainMultiplyFromTop(vector<int> &p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int minCost = -1;
    for (int k = i; k < j; k++)
    {
        int q = chainMultiplyFromTop(p, i, k) + chainMultiplyFromTop(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        minCost = (minCost == -1 || q < minCost) ? q : minCost;
    }
    return minCost;
}

// 自底向上
int chainMultiply(vector<int> &p, int pi, int pj)
{
    int maxSize = p.size();
    int cost[maxSize][maxSize];
    int cutPos[maxSize][maxSize];
    if (maxSize <= 2)
    {
        return 0;
    }
    for (int i = 0; i < maxSize; i++)
    {
        cost[i][i] = 0;
    }
    // 自底向上，cost[][]相当于memo
    // 按照长度递归，从短的开始算
    for (int len = 2; len < maxSize - 1; len++)
    {
        for (int i = 1; i < maxSize - len; i++)
        {
            int j = i + len - 1;
            int minCost = -1;
            for (int k = i; k < j; k++)
            {
                int q = cost[i][k] + cost[k + 1][j] + p[i - 1] * p[j] * p[k];
                minCost = (q < minCost || minCost == -1) ? q : minCost;
            }
            cost[i][j] = minCost;
        }
    }
    return cost[pi][pj];
}

int main(int argc, char const *argv[])
{
    vector<int> data = {30, 35, 15, 5, 10, 20, 25};
    // cout << chainMultiplyFromTop(data, 1, data.size() - 1) << endl;
    // cout << chainMultiplyFromTop(data, 2, 5) << endl;
    cout << chainMultiply(data, 2, 5) << endl;

    return 0;
}
