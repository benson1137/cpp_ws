#pragma once

// 二叉树结点
template <class T>
struct TreeNode
{
    T data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;
    // T类必须有默认构造函数
    // 默认构造函数
    TreeNode() : leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
    // 拷贝构造函数
    // 以下要求T也有拷贝构造函数
    TreeNode(const TreeNode<T> &node) : leftChild(node.leftChild),
                                        rightChild(node.rightChild),
                                        parent(node.parent),
                                        data(node.data) {}
    TreeNode(const T &dt) : leftChild(nullptr),
                            rightChild(nullptr),
                            parent(nullptr),
                            data(dt) {}
    ~TreeNode() {}
};

// 二叉搜索树
template <class T>
class BinTree
{
private:
    TreeNode<T> *root;

public:
    BinTree() : root(nullptr) {}
    // 这个拷贝函数是浅拷贝
    BinTree(const BinTree &bt) : root(bt.root) {}
    ~BinTree() {}
    bool empty() { return root == nullptr; }

    // 遍历：要求T类重载<<操作符
    void preOrderTraverse(TreeNode<T> *rt)
    {
        if (rt == nullptr)
            return;
        operateData(rt->data);
        preOrderTraverse(rt->leftChild);
        preOrderTraverse(rt->leftChild);
    }
    void inOrderTraverse(TreeNode<T> *rt)
    {
        if (rt == nullptr)
            return;
        preOrderTraverse(rt->leftChild);
        operateData(rt->data);
        preOrderTraverse(rt->leftChild);
    }
    void postOrderTraverse(TreeNode<T> *rt)
    {
        if (rt == nullptr)
            return;
        preOrderTraverse(rt->leftChild);
        preOrderTraverse(rt->leftChild);
        operateData(rt->data);
    }
    // 遍历过程中对T对象进行操作
    void operateData(T &t)
    {
        std::cout << t << " ";
    }

    // 查找最大/最小值
    T &minimum(TreeNode<T> *n)
    {
        for (auto it = n; it->leftChild != nullptr; it = it->leftChild)
            ;
        return &(it->data);
    }
    T &maximum(TreeNode<T> *n)
    {
        for (auto it = n; it->rightChild != nullptr; it = it->rightChild)
            ;
        return &(it->data);
    }
    // 查找前驱后继
    T &successorOf(TreeNode<T> *n)
    {
        if (n->rightChild != nullptr)
        {
            return minimum(n->rightChild);
        }
        TreeNode<T> parentOfN = n->parent;
        while (parentOfN != nullptr && n == parentOfN->rightChild)
        {
            n = parentOfN;
            parentOfN = parentOfN->parent;
        }
        // TODO: 测试一下如果parenOfN是nullptr的情况
        return &(*parentOfN);
    }
    T &predecessor(TreeNode<T> *n)
    {
        if (n->leftChild != nullptr)
        {
            return maximum(n - leftChild);
        }
        TreeNode<T> parentOfN = n->parent;
        while (parentOfN != nullptr && n != parentOfN->leftChild)
        {
            n = parentOfN;
            parentOfN = parentOfN->parent;
        }
        // TODO: 测试一下如果parenOfN是nullptr的情况
        return &(*parentOfN);
    }

    // 插入与删除
    // 需要T类别支持比较操作
    void insertNode(T dt)
    {
        TreeNode *it = root;
        TreeNode *parentIt;
        TreeNode newNode = new TreeNode(dt);
        while (it != NULL)
        {
            parentIt = it;
            it = (dt < it->data) ? it->leftChild : it->rightChild;
        }
        newNode->parent = parentIt;
        if (it->parent == nullptr)
        {
            this->root = newNode;
        }
        else if (dt > parentIt->data)
        {
            parentIt->rightChild = newNode;
        }
        else
        {
            parentIt->leftChild = newNode;
        }
    }
    void deleteNode()
    {
    }
};