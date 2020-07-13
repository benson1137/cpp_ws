#pragma once

#include <iostream>
// 用于测试模板的数据类

class Data
{
    friend std::ostream &operator<<(std::ostream &out, const Data &dt);

private:
    int data;

public:
    // 默认构造函数
    Data(int data = 0);
    // 拷贝构造函数
    Data(const Data &tn);
    ~Data();

    // 重载关系、比较运算符
    bool operator<(const Data &dt) { return this->data < dt.data; }
    bool operator<=(const Data &dt) { return this->data <= dt.data; }
    bool operator>(const Data &dt) { return this->data > dt.data; }
    bool operator>=(const Data &dt) { return this->data >= dt.data; }
    bool operator==(const Data &dt) { return this->data == dt.data; }
    bool operator!=(const Data &dt) { return this->data != dt.data; }
};

std::ostream &operator<<(std::ostream &out, const Data &dt);