#include "Character.hpp"

Character::Character(): _name("default")
{
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &copy)
{
	std::cout << "Character copy constructor" << std::endl;
	*this = copy;
}

Character::Character(std::string const &name): _name(name)
{
	std::cout << "Character constructor with name" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

Character &Character::operator=(Character const &rhs)
{
	std::cout << "Character assignation operator" << std::endl;
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = rhs.inventory[i];
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	std::cout << "Character equip" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "equip " << m->getType() << " at " << i << std::endl;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	std::cout << "Character unequip" << std::endl;
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	std::cout << "Character use" << std::endl;
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return std::cout << "not use" << std::endl, void();

	this->inventory[idx]->use(target);
}