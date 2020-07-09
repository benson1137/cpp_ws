#pragma once

#include <iostream>
// 用于测试模板的数据类

class Data
{
    friend std::ostream &operator<<(std::ostream &out, Data dt);

private:
    int data;

public:
    // 默认构造函数
    Data(int data = 0);
    // 拷贝构造函数
    Data(const Data &tn);
    ~Data();
};

std::ostream &operator<<(std::ostream &out, Data dt);