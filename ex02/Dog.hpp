#pragma once

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal{
	public:
		Dog();
		Dog(const Dog &copy);

		~Dog();

		Dog &operator=(const Dog &rhs);

		void makeSound() const;
		Brain *getBrain();
	private:
		Brain *brain;
};
