#ifndef _ATOM_H_
#define _ATOM_H_

#include "iostream"

class Atom
{
    friend std::ostream &operator<<(std::ostream &out, Atom &a);

private:
    int a;

public:
    Atom(int a = 0) : a(a) {}
    ~Atom() {}
    int getA() const { return a; }
};

std::ostream &operator<<(std::ostream &out, Atom &a);

#endif