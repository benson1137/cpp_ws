#include <iostream>
#include "queue.h"

// 实现一个队列

int main(int argc, char const *argv[])
{
    Queue<int> q(3, 10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}
