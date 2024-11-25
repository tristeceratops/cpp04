#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default created" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	std::cout << "Dog copy operator" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}