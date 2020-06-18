#include <iostream>

using namespace std;

typedef unsigned char typo;

int main(int argc, char const *argv[])
{
    typo tab[] = {0, 1, 2, 3, 4, 5, 6};
    typo *p = tab;
    for (int i = 0; i < 7; i++, p++)
    {
        cout << *p << p << endl;
    }
    cout << endl;
    return 0;
}
