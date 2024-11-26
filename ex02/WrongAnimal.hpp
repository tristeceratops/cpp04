#pragma once

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &rhs);

		void makeSound() const;
		std::string getType() const;
		void setType(std::string str);
};
