#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs)
{
	this->type = rhs.type;
	std::cout << "AAnimal copy operator" << std::endl;
	return *this;
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "\033[48;5;232;90;3;1;5mvoid\033[0m" << std::endl;
// }

void AAnimal::setType(std::string str)
{
	this->type = str;
}

std::string AAnimal::getType() const
{
	return this->type;
}