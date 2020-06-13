#include <iostream>

using namespace std;

void test1()
{
    enum Weekdays : int
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    // cout << Weekdays::Monday << endl;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
