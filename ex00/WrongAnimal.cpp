#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->type = rhs.type;
	std::cout << "WrongAnimal copy operator" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[48;5;232;90;3;1;5mvoid\033[0m" << std::endl;
}

void WrongAnimal::setType(std::string str)
{
	this->type = str;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}