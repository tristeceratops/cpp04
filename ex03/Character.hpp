#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
    private:
        struct Node {
            AMateria* materia;
            Node* next;
            Node(AMateria* m) : materia(m), next(NULL) {}
        };

        Node* head; // Head of the linked list

        AMateria* inventory[4];
        std::string _name;
        int inv_index;

        void clearList();
        void copyList(const Character &other);
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