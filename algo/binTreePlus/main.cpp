#include <iostream>
#include "bintree.hpp"
#include "data.hpp"

using namespace std;

// 测试函数
void test1()
{
    Data tNode1;
    TreeNode<Data> tn1(tNode1);
    TreeNode<Data> tn2(tn1);
}

// 主函数
int main(int argc, char const *argv[])
{
    // test1();
    TreeNode<int> *treePtr = new TreeNode<int>(4);
    cout << treePtr->data << endl;
    cout << (long long)(treePtr) << endl;
    delete treePtr;
    cout << (treePtr == NULL) << endl;
    cout << (treePtr == nullptr) << endl;
    cout << (long long)(treePtr) << endl;
    cout << treePtr->data << endl;
    return 0;
}
