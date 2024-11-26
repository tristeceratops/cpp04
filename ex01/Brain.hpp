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
	
	void setIdea(int i, std::string str);
	std::string getIdea(int i);
};
