#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default created" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	std::cout << "Animal copy operator" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "\033[48;5;232;90;3;1;5mvoid\033[0m" << std::endl;
}

void Animal::setType(std::string str)
{
	this->type = str;
}

std::string Animal::getType() const
{
	return this->type;
}