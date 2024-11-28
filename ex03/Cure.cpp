#include "Cure.hpp"

Cure::Cure(){
	std::cout << "Cure empty constructor" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure &copy){
	std::cout << "Cure copy constructor" << std::endl;
	*this = copy;
}

Cure::~Cure(){
	std::cout << "Cure destructor" << std::endl;
}

Cure & Cure::operator=(const Cure &rhs){
	std::cout << "Cure copy operator" << std::endl;
	this->_type = rhs._type;
	return *this;
}

Cure* Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}