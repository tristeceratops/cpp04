#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice empty constructor" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	// std::cout << "Ice copy constructor" << std::endl;
	//*this = copy;
	(void) copy;
}

Ice::~Ice(){
	// std::cout << "Ice destructor" << std::endl;
}

Ice & Ice::operator=(const Ice &rhs){
	// std::cout << "Ice copy operator" << std::endl;
	(void) rhs;
	return *this;
}

Ice* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}