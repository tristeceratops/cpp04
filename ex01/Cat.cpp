#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default created" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy operator" << std::endl;
	if (this != &rhs){
		delete this->brain;
		this->brain = new Brain();
		*(this->brain) = *(rhs.brain);
		this->type = rhs.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
}

Brain* Cat::getBrain()
{
	return this->brain;
}
