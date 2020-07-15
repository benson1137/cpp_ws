#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

void passed_by_primer(int *i)
{
    *i = 0;
}

// 使用非常量引用的缺陷：
// 传入字面值时将报错
void passed_by_reference(string &s)
{
    cout << s << endl;
}
void passed_by_const_ref(const string &s)
{
    cout << s << endl;
}

// 数组形参
void array_pass(int a[10])
{
    // 形参里面写的10没有意义
    // 编译器只检查传入的参数是不是int*
    cout << a[11] << endl;
}

// 可变形参
// 传值的时候用中括号
void variable_params(initializer_list<string> lst)
{
    for (auto i = lst.begin(); i != lst.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int i = 2;
    int *p = &i;
    passed_by_primer(p);
    cout << i << endl;

    // 非常量引用的缺陷
    // 传入字面值将报错
    // passed_by_reference("123123123");
    string ss = "123123123";
    passed_by_reference(ss);
    passed_by_const_ref("123123123");
    passed_by_const_ref(ss);

    int array_a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    array_pass(array_a);

    // begin() 和 end() 获取头尾指针
    cout << *begin(array_a) << *(end(array_a) - 1) << endl;

    variable_params({"1211", "12123", "221"});
    variable_params({"1211", "12123"});
    return 0;
}
