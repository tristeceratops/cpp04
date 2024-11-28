#include "AMateria.hpp"

AMateria::AMateria(): _type("")
{
	std::cout << "materia empty constructor" << std::endl;
}

AMateria::AMateria(const AMateria &copy){
	*this = copy;
	std::cout << "materia empty constructor" << std::endl;
}

AMateria::AMateria(std::string const &type){
	(void) type;
	std::cout << "materia constructor with type" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "materia destructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &rhs){
	(void) rhs;
	std::cout << "materia copy operator" << std::endl;
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target){
	(void) target;
	std::cout << "materia use" << std::endl;
}