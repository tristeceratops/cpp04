#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string _type;
	public:
		Ice();
		Ice(const Ice &copy);

		~Ice();
		
		Ice &operator=(const Ice &rhs);

		Ice* clone() const;
		void use(ICharacter &target);
};