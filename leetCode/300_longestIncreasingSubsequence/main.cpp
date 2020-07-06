#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int> length(nums.size());
        int maxIndex = 0;
        int maxLength = 1;
        length[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[maxIndex])
            {
                length[i] = length[maxIndex] + 1;
            }
            else if (nums[i] < nums[maxIndex])
            {
                int lengthBeforeI = 0;
                for (int j = 0; j < i; j++)
                {
                    lengthBeforeI = (nums[j] < nums[i] && length[j] > lengthBeforeI) ? (length[j]) : lengthBeforeI;
                }
                length[i] = lengthBeforeI + 1;
            }
            else
            {
                length[i] = length[i - 1];
            }
            maxLength = (maxLength > length[i]) ? maxLength : length[i];
            maxIndex = (maxLength > length[i]) ? maxIndex : i;
        }
        return maxLength;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> data = {1, 2, 3, 4};
    // vector<int> data = {2, 1, 5, 4, 3, 2, 4, 5, 6};
    // vector<int> data = {1};
    vector<int> data = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution sln;
    cout << sln.lengthOfLIS(data) << endl;
    return 0;
}
