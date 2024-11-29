#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure empty constructor" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	std::cout << "Cure copy constructor" << std::endl;
	(void) copy;
}

Cure::~Cure(){
	std::cout << "Cure destructor" << std::endl;
}

Cure & Cure::operator=(const Cure &rhs){
	std::cout << "Cure copy operator" << std::endl;
	(void) rhs;
	//this->_type = rhs._type;
	return *this;
}

Cure* Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}