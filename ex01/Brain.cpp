#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default created" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain& Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain copy operator" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string str)
{
	if (i >= 0 && i < 100){
		this->ideas[i] = str;
	}
}

std::string Brain::getIdea(int i)
{
	if (i >= 0 && i < 100){
		return this->ideas[i];
	}
	return "";
}
