#include "data.hpp"

// 默认构造函数
Data::Data(int data) : data(data) {}
// 拷贝构造函数
Data::Data(const Data &tn) : data(tn.data) {}
// 析构
Data::~Data() {}

std::ostream &operator<<(std::ostream &out, const Data &dt)
{
    out << dt.data;
    return out;
}