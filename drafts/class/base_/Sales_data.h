#pragma once
#include <iostream>

class Sales_data
{
    // 友元函数
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

private:
    /* data */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;

public:
    // 构造函数
    // 要求编译器生成默认构造函数，在类的内部时默认是内联的
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(std::istream &);

    // 析构函数
    ~Sales_data();

    // 成员函数
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);