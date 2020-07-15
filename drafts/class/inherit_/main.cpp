#include <iostream>
#include "point.h"
#include "rectangle.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Rectangle r;
    r.initRectangle(1, 2, 3, 4);
    cout << r.getX() << endl
         << r.getY() << endl
         << r.getW() << endl
         << r.getH() << endl;
}
