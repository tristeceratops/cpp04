#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default created" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	this->type = rhs.type;
	std::cout << "Cat copy operator" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}