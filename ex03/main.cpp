#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <stdio.h>

int main()
{
	std::cout << "Main tests of subject **************************" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "Test does not exists Material ******************* " << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		tmp = src->createMateria("fire");
		if (tmp != NULL)
			me->equip(tmp);
		else
			std::cout << "Returned NULL because it does not exists." << std::endl;
		tmp = src->createMateria("fire");
		delete me;
		delete src;
	}

	std::cout << "Test unequip character ******************* " << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		for (int i = 0; i < 42; i++)
			src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->equip(tmp);
		me->equip(tmp);
		me->equip(tmp);
		for (int i = 0; i < 42; i++)
			me->equip(tmp);
		ICharacter* bob = new Character("Bobby");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;		
	}
	std::cout << "Test use bad index ******************* " << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(67, *bob);
		me->use(-1, *bob);
		me->use(3, *bob);
		delete bob;
		delete me;
		delete src;		
	}
	std::cout << "Test unequip ******************* " << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		me->unequip(1);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout <<"\tWe are going to unequip 1." << std::endl;
		me->unequip(1);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;		
	}
}