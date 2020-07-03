#include <iostream>
#include <algorithm>

int priceTable[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int memoTable[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int paramCnt[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

// 切钢条问题的递归实现
// 切一段长度为n的，剩下部分的用递归方法求解
// 自顶向下的朴素递归方法效率低
int naiveFromTopCutRod(int pTable[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    paramCnt[n]++;
    int maxPrice = -1;
    // 这里重要的不是循环次数，i的值不能为0
    for (int i = 1; i <= n; i++)
    {
        maxPrice = std::max(maxPrice, pTable[i - 1] + naiveFromTopCutRod(pTable, n - i));
    }
    return maxPrice;
}

// 带备忘
int memoFromTopCutRod(int pTable[], int memo[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (memo[n] != 0)
    {
        return memo[n];
    }
    paramCnt[n]++;
    int maxPrice = -1;
    // 这里重要的不是循环次数，i的值不能为0
    for (int i = 1; i <= n; i++)
    {
        maxPrice = std::max(maxPrice, pTable[i - 1] + memoFromTopCutRod(pTable, memo, n - i));
    }
    // 更新memo
    memo[n] = maxPrice;
    return maxPrice;
}

// 自底向上
int memoFromBottomCutRod(int pTable[], int memo[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int maxPrice = -1;
        for (int j = 1; j <= i; j++)
        {
            maxPrice = std::max(maxPrice, pTable[j - 1] + memo[i - j]);
        }
        memo[i] = maxPrice;
    }
    return memo[n];
}

using namespace std;
int main(int argc, char const *argv[])
{
    // 自顶向下的朴素递归方法
    // cout << naiveFromTopCutRod(priceTable, 8) << endl;
    // 带备忘的自顶向下
    // cout << memoFromTopCutRod(priceTable, memoTable, 8) << endl;
    // 自底向上
    cout << memoFromBottomCutRod(priceTable, memoTable, 8) << endl;

    // 显示每个cutRod(n)计算了多少次
    int index = 0;
    for (int i : paramCnt)
    {
        cout << index << " " << i << endl;
        index++;
    }
    return 0;
}
