#pragma once

#include <iostream>

class Brain{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &copy);

	~Brain();

	Brain &operator=(const Brain &rhs);

};
