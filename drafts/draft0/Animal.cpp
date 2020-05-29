#include "Animal.h"
// #include <string>
// #include <iostream>

Animal::Animal()
{
    name = "name";
}

Animal::~Animal()
{
    std::cout << name << std::endl;
}