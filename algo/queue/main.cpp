#include <iostream>
#include "queue.h"

// 实现一个队列

class Vertex
{
private:
    int i;
    char c;

public:
    Vertex() : i(0), c(' ') {}
    Vertex(int i, char c) : i(i), c(c) {}
    Vertex(Vertex &v) : i(v.i), c(v.c) {}
    Vertex(const Vertex &v) : i(v.i), c(v.c) {}
    ~Vertex() {}
};

void testOfInt()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
}

void testOfVertex()
{
    Queue<Vertex> q;
    q.enqueue(Vertex(0, 'A'));
    q.enqueue(Vertex(1, 'B'));
    q.enqueue(Vertex(2, 'C'));
    q.enqueue(Vertex(3, 'D'));
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}

int main(int argc, char const *argv[])
{
    testOfVertex();
    return 0;
}
