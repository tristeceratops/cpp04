#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	this->type = rhs.type;
	std::cout << "WrongCat copy operator" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}