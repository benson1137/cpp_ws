#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

// 模板类的文件组织方式
// 声明与实现最好写到一起

#include <cassert>
#include <iostream>

template <class T>
class DyList
{
private:
    T *array;
    int size;

public:
    DyList(int s = 10);
    DyList(const DyList<T> &src);
    ~DyList() { delete[] array; }

    //赋值操作
    DyList<T> &operator=(const DyList<T> &src);

    // 返回的结果可以放在=左边
    T &operator[](int index);
    // 用来读取成员的值，返回一个常量值
    const T &operator[](int index) const;

    // 重载T*操作
    operator T *();
    operator const T *() const;

    int getSize() const { return size; }
    void resize(int s);
};

template <class T>
DyList<T>::DyList(int s)
{
    assert(s >= 0);
    size = s;
    array = new T[size];
}

template <class T>
DyList<T>::DyList(const DyList<T> &src)
{
    size = src.size;
    array = new T[size];
    for (int i = 0; i < size; i++)
        this->array[i] = src.array[i];
}

template <class T>
DyList<T> &DyList<T>::operator=(const DyList<T> &src)
{
    if (&src != this)
    {
        if (size == src.size)
        {
            delete[] array;
            size = src.getSize();
            array = new T[size];
        }
        for (int i = 0; i < size; i++)
            array[i] = src.array[i];
    }
    return *this;
}

template <class T>
T &DyList<T>::operator[](int index)
{
    assert(index >= 0 && index < size);
    return array[index];
}

template <class T>
const T &DyList<T>::operator[](int index) const
{
    assert(index >= 0 && index < size);
    return array[index];
}

template <class T>
DyList<T>::operator T *()
{
    return array;
}

template <class T>
DyList<T>::operator const T *() const
{
    return array;
}

template <class T>
void DyList<T>::resize(int s)
{
    if (s == size)
        return;
    else
    {
        T *tmp = new T[s];
        for (int i = 0; i < (s < size ? s : size); i++)
            tmp[i] = array[i];
        delete[] array;
        array = tmp;
    }
}

#endif