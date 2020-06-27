// 1.后缀表达式->中缀表达式
// 2.计算中缀表达式

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "stack.h"

using namespace std;

constexpr int oprt2Num(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
        break;
    }
}

vector<string> infix2Postfix(string s)
{
    vector<string> expr;
    Stack<char> oprt_stack;
    string temp;
    for (char i : s)
    {
        if (isdigit(i))
            temp.push_back(i);
        else
        {
            // 把之前缓存的数字输出
            expr.push_back(temp);
            temp.clear();
            // 处理符号
            // 如果符号栈空，则push
            if (oprt_stack.empty())
                oprt_stack.push(i);
            // 符号栈不为空，且当前符号优先级大于栈顶符号，则push
            else if (oprt2Num(i) > oprt2Num(oprt_stack.getTopElement()))
                oprt_stack.push(i);
            // 符号栈不为空，且当前符号优先级<=栈顶符号，则依次出栈
            else
            {
                while (!oprt_stack.empty())
                {
                    temp.push_back(oprt_stack.getTopElement());
                    oprt_stack.pop();
                    expr.push_back(temp);
                    temp.clear();
                }
                // 处理完之前的符号，将本次的符号入栈
                oprt_stack.push(i);
            }
        }
    }
    expr.push_back(temp);
    temp.clear();

    // 符号栈中剩余的符号出栈
    while (!oprt_stack.empty())
    {
        temp.push_back(oprt_stack.getTopElement());
        oprt_stack.pop();
        expr.push_back(temp);
        temp.clear();
    }

    // for (auto item : expr)
    // cout << item << endl;
    return expr;
}

int calculatePostfix(string s)
{
    vector<string> data = infix2Postfix(s);
    Stack<int> num_stack;
    for (string s : data)
    {
        int temp;
        // 如果是数字就入栈
        if (isdigit(s[0]))
        {
            stringstream ss(s);
            ss >> temp;
            num_stack.push(temp);
        }
        else
        {
            int num2 = num_stack.getTopElement();
            num_stack.pop();
            int num1 = num_stack.getTopElement();
            num_stack.pop();
            switch (s[0])
            {
            case '+':
                num_stack.push(num1 + num2);
                break;
            case '-':
                num_stack.push(num1 - num2);
                break;
            case '*':
                num_stack.push(num1 * num2);
                break;
            case '/':
                num_stack.push(num1 / num2);
                break;
            default:
                break;
            }
        }
    }
    if (num_stack.size() == 1)
        return num_stack.getTopElement();
    else
    {
        cout << "error" << endl;
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    // cout << infix2Postfix("1+2*3+9*78");
    cout << calculatePostfix("11-11*7+44") << endl;
    return 0;
}
