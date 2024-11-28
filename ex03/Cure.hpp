#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string _type;
	public:
		Cure();
		Cure(const Cure &copy);

		~Cure();

		Cure &operator=(const Cure &rhs);
		
		Cure* clone() const;
		void use(ICharacter &target);
};