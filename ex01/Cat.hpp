#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(const Cat &copy);

		~Cat();

		Cat &operator=(const Cat &rhs);

		void makeSound() const;
		Brain *getBrain();
		Animal *clone() const;
	private:
		Brain *brain;
};
