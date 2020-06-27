#include <iostream>
#include <vector>

using namespace std;

int totalFruit(vector<int> &tree)
{
}

int main(int argc, char const *argv[])
{
    // vector<int> t = {1, 2, 2, 3, 2, 2, 4, 2, 2, 1, 1, 1, 1, 1};
    vector<int> t = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << totalFruit(t) << endl;
    return 0;
}
