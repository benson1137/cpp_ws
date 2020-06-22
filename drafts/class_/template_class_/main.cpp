#include "iostream"
#include "dynamicArray.h"
#include "atom.h"

using namespace std;

int main(int argc, char const *argv[])
{
    DyList<Atom> numList(10);
    cout << numList.getSize() << endl;
    for (int i = 0; i < numList.getSize(); i++)
        numList[i] = Atom(i);

    for (int i = 0; i < numList.getSize(); i++)
        cout << numList[i] << "\t";
    cout << endl;

    DyList<Atom> numList_1(numList);
    for (int i = 0; i < numList_1.getSize(); i++)
        cout << numList_1[i] << "\t";
    cout << endl;

    numList_1[0] = Atom(100);

    cout << "------------" << endl;
    for (int i = 0; i < numList.getSize(); i++)
        cout << numList[i] << "\t";
    cout << endl;
    for (int i = 0; i < numList_1.getSize(); i++)
        cout << numList_1[i] << "\t";
    cout << endl;

    return 0;
}
