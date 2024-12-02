#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
    private:
        AMateria* inventory[4];
        AMateria* memory[100];
        std::string _name;
		int index;
    public:
        Character();
        Character(Character const &copy);
        Character(std::string const &name);

        ~Character();

        Character &operator=(Character const &rhs);

        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};