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
    Node() : next(nullptr) { data = T(); }
    Node(T data) : data(data), next(nullptr) {}
    ~Node() {}
    // T getData() const { return data; }
};

template <class T>
class Queue
{
private:
    // 首元素的前一个
    Node<T> *front;
    // 尾元素
    Node<T> *end;
    int queue_size;

public:
    Queue() : queue_size(0)
    {
        front = new Node<T>;
        end = front;
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
        // 空队列，返回错误信息
        if (empty())
        {
            std::cout << "Empty Queue! Can't Deque!" << std::endl;
        }
        // 只有一个元素
        else if (queue_size == 1)
        {
            delete end;
            end = front;
            front->next = nullptr;
            queue_size--;
        }
        // 多个元素
        else
        {
            Node<T> *tmp = front->next;
            front->next = tmp->next;
            delete tmp;
            queue_size--;
        }
    }
    bool empty() { return front == end; }
};

#endif