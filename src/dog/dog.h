#ifndef __DOG_H_
#define __DOG_H_
#include <iostream>
#include <ostream>
#include <string>

class Dog
{
public:
    Dog();
    Dog(int && age, std::string && name) : age(age), name(name) {};
    ~Dog();

    friend std::ostream& operator<< (std::ostream& os, const Dog &ob);
private:
    int age{0};
    std::string name{std::string("none")};
protected:
};

#endif