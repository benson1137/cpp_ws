#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int height = grid.size();
        int width = grid[0].size();
        int pathSum[height][width];
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (i == 0 && j == 0)
                {
                    pathSum[i][j] = grid[i][j];
                    continue;
                }
                if (i == 0)
                {
                    pathSum[i][j] = pathSum[i][j - 1] + grid[i][j];
                    continue;
                }
                if (j == 0)
                {
                    pathSum[i][j] = pathSum[i - 1][j] + grid[i][j];
                    continue;
                }
                pathSum[i][j] = min(pathSum[i - 1][j], pathSum[i][j - 1]) + grid[i][j];
            }
        }
        return pathSum[height - 1][width - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> map = {
        {1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution sln;
    cout << sln.minPathSum(map) << endl;
    return 0;
}
