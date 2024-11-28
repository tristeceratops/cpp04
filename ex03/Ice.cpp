#include "Ice.hpp"

Ice::Ice(){
	std::cout << "Ice empty constructor" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice &copy){
	std::cout << "Ice copy constructor" << std::endl;
	*this = copy;
}

Ice::~Ice(){
	std::cout << "Ice destructor" << std::endl;
}

Ice & Ice::operator=(const Ice &rhs){
	std::cout << "Ice copy operator" << std::endl;
	return *this;
}

Ice* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter &target){

}