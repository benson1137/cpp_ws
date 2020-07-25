#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        vector<TreeNode *> res = generate(1, n);
        return res;
    }
    vector<TreeNode *> generate(int beginIndex, int endIndex)
    {
        vector<TreeNode *> res;
        if (beginIndex > endIndex)
        {
            return {nullptr};
        }
        if (beginIndex == endIndex)
        {
            res.push_back(new TreeNode(beginIndex));
            return res;
        }
        // 不同的数作根节点
        for (int i = beginIndex; i <= endIndex; ++i)
        {
            vector<TreeNode *> leftList = generate(beginIndex, i - 1);
            vector<TreeNode *> rightList = generate(i + 1, endIndex);
            if (leftList.empty())
            {
                for (TreeNode *&right : rightList)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = nullptr;
                    root->right = right;
                    res.push_back(root);
                }
                continue;
            }
            if (rightList.empty())
            {
                for (TreeNode *&left : leftList)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = nullptr;
                    res.push_back(root);
                }
                continue;
            }
            for (TreeNode *&left : leftList)
            {
                for (TreeNode *&right : rightList)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<TreeNode *> treeList = sln.generate(4, 5);
    return 0;
}
