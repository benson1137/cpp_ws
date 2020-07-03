#include <iostream>
#include <sstream>
#include <string>

class BinTree;

class Node
{
    friend class BinTree;

private:
    char data;
    Node *lchild;
    Node *rchild;

public:
    Node(int dt = 0) : data(dt), lchild(nullptr), rchild(nullptr) {}
    ~Node() {}
};

class BinTree
{
private:
    Node *root;
    int tree_size;
    void constructFromKeyboard(Node *&T, std::stringstream &ss)
    {
        char tmp;
        ss >> tmp;
        if (tmp == '#')
            ;
        else
        {
            T = new Node(tmp);
            tree_size++;
            constructFromKeyboard(T->lchild, ss);
            constructFromKeyboard(T->rchild, ss);
        }
    }
    // 前序遍历
    void preOrder(Node *T)
    {
        if (T != nullptr)
        {
            std::cout << T->data << " ";
            preOrder(T->lchild);
            preOrder(T->rchild);
        }
    }
    // 中序遍历
    void inOrder(Node *T)
    {
        if (T != nullptr)
        {
            inOrder(T->lchild);
            std::cout << T->data << " ";
            inOrder(T->rchild);
        }
    }
    // 后序遍历
    void postOrder(Node *T)
    {
        if (T != nullptr)
        {
            postOrder(T->lchild);
            postOrder(T->rchild);
            std::cout << T->data << " ";
        }
    }

public:
    BinTree() : tree_size(0), root(nullptr) {}
    BinTree(std::stringstream &ss) : tree_size(0), root(nullptr) { constructFromKeyboard(root, ss); }
    ~BinTree() {}
    int size() const { return tree_size; }
    void preOrderTraverse() { preOrder(root); }
    void inOrderTraverse() { inOrder(root); }
    void postOrderTraverse() { postOrder(root); }
};

using namespace std;

int main(int argc, char const *argv[])
{
    // string s = "A B # D # # C # #";
    string s = "A B D H # K # # # E # # C F I # # # G # J # #";
    stringstream ss(s);
    BinTree bt(ss);
    bt.preOrderTraverse();
    cout << endl;
    bt.inOrderTraverse();
    cout << endl;
    bt.postOrderTraverse();
    cout << endl;
    return 0;
}