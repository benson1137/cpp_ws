#include <iostream>
#include <string>

#define PRINT(X) cout << end(X) - begin(X) << endl

using namespace std;

void array_init()
{
    // 正常
    int a1[3] = {0, 1, 2};
    // 未初始化的自动补0
    int a2[5] = {0, 1, 2};
    // 自动补空字符串
    string s1[3] = {"Hello", "World"};

    // 字符串数组的\0问题

    // 按照字面值初始化，没有\0
    char s2[] = {'C', '+', '+'};
    // 字面值初始化，有\0
    char s3[] = {'C', '+', '+', '\0'};

    // 这个等价于s3，自动补\0
    char s4[] = "C++";

    // cout << end(a1) - begin(a1) << endl;
    PRINT(a1);
    PRINT(a2);
    PRINT(s1);
    // s2长度是3
    PRINT(s2);
    // s3和s4长度是4
    PRINT(s3);
    PRINT(s4);
}

void complicated_array()
{
    // 正常的
    int a[10] = {};
    // 10个int*指针的数组
    int *p1[10];
    // pArray指向一个含有10个整数的数组
    int(*pArray)[10] = &a;
    // rArray引用一个含有10个整数的数组
    int(&rArray)[10] = a;

    // pArray是指向数组a的指针
    PRINT(*pArray);
    // rArray是对数组a的引用
    PRINT(rArray);
}

int main(int argc, char const *argv[])
{
    // array_init();
    complicated_array();
    return 0;
}
