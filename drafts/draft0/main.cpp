#include <iostream>
#include <vector>

using namespace std;

// vector<int> dailyTemperatures(vector<int> &T)
// {
//     vector<int> result(T.size(), 0);
//     vector<int> tStack;
//     vector<int> indexStack;
//     for (int i = 0; i < T.size(); i++)
//     {
//         while (!tStack.empty() && tStack.back() < T[i])
//         {
//             result[indexStack.back()] = i - indexStack.back();
//             tStack.pop_back();
//             indexStack.pop_back();
//         }
//         tStack.push_back(T[i]);
//         indexStack.push_back(i);
//     }
//     return result;
// }

vector<int> dailyTemperatures(vector<int> &T)
{
    int maxSize = T.size();
    vector<int> result(maxSize, 0);
    int tStack[maxSize + 1];
    int indexStack[maxSize + 1];
    int stackTopPtr = 0;
    for (int i = 0; i < maxSize; i++)
    {
        while (stackTopPtr && tStack[stackTopPtr] < T[i])
        {
            result[indexStack[stackTopPtr]] = i - indexStack[stackTopPtr];
            stackTopPtr--;
        }
        stackTopPtr++;
        tStack[stackTopPtr] = T[i];
        indexStack[stackTopPtr] = i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> temperature = {73, 74, 75, 71, 69, 72, 76, 77};
    cout << temperature.back() << endl;
    vector<int> result = dailyTemperatures(temperature);
    for (int i : result)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
