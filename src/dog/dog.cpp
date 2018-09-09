#include "dog.h"

Dog::Dog()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Dog::~Dog()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::ostream& operator<< (std::ostream& os, const Dog &ob)
{
    os << "Name: " << ob.name << std::endl << "Age: " << ob.age << std::endl; 
}