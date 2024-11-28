#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter {
	private:
		AMateria* inventory[4];
		std::string _name;
	public:

};