#pragma once

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(const Dog &copy);

		~Dog();

		Dog &operator=(const Dog &rhs);

		void makeSound() const;
	private:
		Brain *brain;
};