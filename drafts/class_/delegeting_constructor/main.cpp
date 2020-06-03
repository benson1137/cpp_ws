#include <iostream>
#include <string>

class Animal
{
public:
    std::string name;
    int leg_num;
    bool has_tail;
    double weight;
    double length;
    // Original Constructor
    Animal(std::string s, int n, bool t, double w, double l) : name(s), leg_num(n), has_tail(t), weight(w), length(l) {}

    // delegating constructor
    Animal(std::string s) : Animal(s, 0, false, 0.0, 0.0) {}
    Animal(int n) : Animal("", n, false, 0.0, 0.0) {}
    Animal(std::string s, int n) : Animal(s, n, false, 0.0, 0.0) {}
};

int main(int argc, char const *argv[])
{
    Animal a1 = Animal("animal1");
    Animal a2 = Animal("animal2", 4);
    std::cout << a1.name << std::endl;
    std::cout << a2.name << std::endl;
    return 0;
}
