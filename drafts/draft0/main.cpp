#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    for (auto numIterator = nums.cbegin(); numIterator != nums.cend(); numIterator++)
}

int main(int argc, char const *argv[])
{
    vector<int> data = {1, 3, 5, 6, 8, 2, 1, 2, 3, 4, 3, 4, 5, 6, 7, 6, 7, 8, 9, 8, 9, 10};
    cout << lengthOfLIS(data) << endl;
    return 0;
}
