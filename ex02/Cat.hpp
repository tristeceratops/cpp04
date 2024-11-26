#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
	public:
		Cat();
		Cat(const Cat &copy);

		~Cat();

		Cat &operator=(const Cat &rhs);

		void makeSound() const;
		Brain *getBrain();
	private:
		Brain *brain;
};
