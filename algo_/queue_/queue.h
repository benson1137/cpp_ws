#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

template <class T>
class Queue;

template <class T>
class Node
{
    friend class Queue<T>;

private:
    T data;
    Node<T> *next;

public:
    Node(int data = 0) : data(data), next(nullptr) {}
    ~Node() {}
    // T getData() const { return data; }
};

template <class T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *end;
    int queue_size;

public:
    Queue(int sz = 0, T dt = 0) : queue_size(sz)
    {
        front = new Node<T>;
        end = front;
        for (int i = 0; i < sz; i++)
            enqueue(dt);
    }
    ~Queue()
    {
        while (!empty())
            dequeue();
        delete front;
    }
    void enqueue(T dt)
    {
        end->next = new Node<T>(dt);
        end = end->next;
        queue_size++;
    }
    void dequeue()
    {
        if (!empty())
        {
            Node<T> *tmp = front->next;
            front->next = tmp->next;
            delete tmp;
            queue_size--;
        }
        else
        {
            std::cout << "Empty Queue! Can't Deque!" << std::endl;
        }
    }
    bool empty() { return front == end; }
};

#endif