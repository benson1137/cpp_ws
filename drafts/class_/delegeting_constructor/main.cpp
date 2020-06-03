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

    // friend void show_animal_name(Animal a);

    // Original Constructor
    Animal(std::string s, int n, bool t, double w, double l) : name(s), leg_num(n), has_tail(t), weight(w), length(l) {}

    // delegating constructor
    Animal(std::string s) : Animal(s, 0, false, 0.0, 0.0) {}
    // explicit禁止隐式转换
    Animal(int n) : Animal("default", n, false, 0.0, 0.0) {}
    // explicit Animal(int n) : Animal("default", n, false, 0.0, 0.0) {}

    Animal(std::string s, int n) : Animal(s, n, false, 0.0, 0.0) {}
};

void show_animal_name(Animal a)
{
    std::cout << "In func " << a.name << std::endl;
}

int main(int argc, char const *argv[])
{
    Animal a1 = Animal("animal1");
    Animal a2 = Animal("animal2", 4);
    std::cout << a1.name << std::endl;
    std::cout << a2.name << std::endl;
    show_animal_name(a1);

    // 这里调用了构造函数Animal(int n)创建了一个临时的Animal对象
    // 隐式转换：4由int转换为Animal，输出名字为"default"
    // 如果Animal(int n)定义为explicit，则这里编译不通过
    show_animal_name(4);
    return 0;
}
