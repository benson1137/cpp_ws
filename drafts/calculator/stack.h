#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

template <class T>
class Stack;

template <class T>
std::ostream &operator<<(std::ostream &out, Stack<T> &ss);

template <class T>
class Node
{
    // template <class T>
    friend class Stack<T>;
    friend std::ostream &operator<<<T>(std::ostream &out, Stack<T> &ss);

private:
    T data;
    Node *next;

public:
    Node(T dt = 0) : data(dt), next(nullptr) {}
    ~Node() {}
    // T getData() const { return data; }
};

template <class T>
class Stack
{
    friend std::ostream &operator<<<T>(std::ostream &out, Stack<T> &ss);

private:
    Node<T> *top;
    // 定义一个栈底，表示最下面一个元素的再下一个元素，类似end()
    Node<T> *bottom;
    int stack_size;

public:
    // push的时候会给size赋值，所以参数列表将size初始化为0
    // Stack() : stack_size(0) { bottom = new Node<T>; }
    Stack(int sz = 0, T dt = 0) : stack_size(0)
    {
        bottom = new Node<T>;
        top = bottom;
        for (int i = 0; i < sz; i++)
            push(dt);
    }
    ~Stack()
    {
        while (top != bottom)
            pop();
        delete bottom;
    }
    void pop()
    {
        if (top != bottom)
        {
            Node<T> *tmp = top;
            top = top->next;
            delete tmp;
            stack_size--;
        }
        else
        {
            std::cout << "Can't pop! Empty Stack!" << std::endl;
        }
    }
    void push(T dt)
    {
        Node<T> *nt = new Node<T>(dt);
        nt->next = top;
        top = nt;
        stack_size++;
    }
    int size() const { return stack_size; }
    bool empty() const { return top == bottom; }
    T getTopElement() const { return this->top->data; }
};

template <class T>
std::ostream &operator<<(std::ostream &out, Stack<T> &ss)
{
    for (auto it = ss.top; it != ss.bottom; it = it->next)
        out << it->data << std::endl;
    return out;
}

#endif