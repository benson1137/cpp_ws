#include "Sales_data.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    std::cout << "Hello WSL!" << std::endl;
    Sales_data s = Sales_data();
    cout << s.isbn() << endl;
    return 0;
}
