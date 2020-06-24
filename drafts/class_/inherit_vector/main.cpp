#include <iostream>
#include <vector>

using namespace std;

template <class T>
ostream &operator<<(ostream &out, vector<T> &vi)
{
    for (auto i = vi.cbegin(); i != vi.cend() - 1; i++)
        cout << *i << "\t";
    cout << *(vi.cend() - 1);
    return out;
}

int main(int argc, char const *argv[])
{
    vector<int> a(10, 0);
    cout << a << endl;
    return 0;
}
