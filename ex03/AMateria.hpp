#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		const std::string _type;
		AMateria();
		AMateria(const AMateria &copy);
	public:
		AMateria(std::string const &type);

		virtual ~AMateria();

		AMateria &operator=(const AMateria &rhs);

		std::string const &getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};