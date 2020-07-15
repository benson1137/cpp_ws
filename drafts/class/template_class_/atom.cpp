#include "atom.h"

std::ostream &operator<<(std::ostream &out, Atom &a)
{
    out << a.a;
    return out;
}