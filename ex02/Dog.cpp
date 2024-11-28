#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default created" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete this->brain;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy operator" << std::endl;
	if (this != &rhs){
		delete this->brain;
		this->brain = new Brain();
		*(this->brain) = *(rhs.brain);
		this->type = rhs.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}

Brain* Dog::getBrain()
{
	return this->brain;
}