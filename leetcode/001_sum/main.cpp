#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (nums[j] + nums[i] == target)
                {
                    return vector<int>({min(i, j), max(i, j)});
                }
            }
        }
        return vector<int>({0});
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    vector<int> a({});
    int target = 99;
    vector<int> r;
    r = solution.twoSum(a, target);
    for (auto i : r)
        cout << i << "\t";
}