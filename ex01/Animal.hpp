#pragma once

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copy);

		virtual ~Animal();

		Animal &operator=(const Animal &rhs);

		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string str);
};
