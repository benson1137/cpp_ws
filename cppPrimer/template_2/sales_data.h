#ifndef SALES_DATA_H
#define SALES_DATA_H

// #include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0; //售出数量
    double revenue = 0.0;    //单价
};

#endif