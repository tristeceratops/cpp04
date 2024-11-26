#pragma once

#include <iostream>

class AAnimal {
	protected:
		std::string type;
		AAnimal();
		AAnimal(const AAnimal &copy);
	public:

		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;
		void setType(std::string str);
};
