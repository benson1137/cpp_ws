#include <iostream>
#include <vector>
#include <string>

// adaptor
#include <stack>
#include <queue>

using namespace std;
// 栈
void stackTest()
{
    string s = "wdnmd";
    stack<char> stk;
    for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
    {
        stk.push(*iter);
    }
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
}
// 队列
void queueTest()
{
    string s = "wdnmd";
    queue<char> que;
    for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
    {
        que.push(*iter);
    }
    while (!que.empty())
    {
        cout << que.front() << endl;
        que.pop();
    }
}
// 优先队列，大的先出
void priorityQueueTest()
{
    string s = "wdnmd";
    // 元素类支持比较大小操作
    priority_queue<char> que;
    for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
    {
        que.push(*iter);
    }
    while (!que.empty())
    {
        cout << que.top() << endl;
        que.pop();
    }
}

int main(int argc, char const *argv[])
{
    // stackTest();
    // queueTest();
    priorityQueueTest();
    return 0;
}
