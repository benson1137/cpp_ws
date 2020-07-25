#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0])
            return 0;
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        int pathNum[height][width];
        pathNum[0][0] = 1;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j])
                {
                    pathNum[i][j] = 0;
                    continue;
                }
                if (i == 0)
                {
                    pathNum[i][j] = pathNum[i][j - 1];
                    continue;
                }
                if (j == 0)
                {
                    pathNum[i][j] = pathNum[i - 1][j];
                    continue;
                }
                pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
            }
        }
        return pathNum[height - 1][width - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<int>> map = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 0, 0}};
    cout << sln.uniquePathsWithObstacles(map) << endl;
    return 0;
}
