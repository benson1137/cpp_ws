#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>

using namespace std;

inline double squreRoot(double x) { return sqrt(x); }

// 输入输出流迭代器
void streamIterator()
{
    transform(istream_iterator<double>(cin), istream_iterator<double>(),
              ostream_iterator<double>(cout, "\n"), squreRoot);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    streamIterator();
    return 0;
}
