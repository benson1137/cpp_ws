#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

void range_exceptions()
{
    char a[10];
    try
    {
        ;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int argc, char const *argv[])
{
    range_exceptions();
    return 0;
}
