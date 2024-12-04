#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
    private:
        struct Node {
            AMateria* materia;
            Node* next;
            Node(AMateria* m) : materia(m), next(NULL) {}
        };

        AMateria *materias[4];
        Node* head; // Head of the linked list
        int materiaCount;

        void clearList();
        void copyList(const MateriaSource &other);

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);

        MateriaSource &operator=(const MateriaSource &other);
        
        ~MateriaSource();
        
        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
};