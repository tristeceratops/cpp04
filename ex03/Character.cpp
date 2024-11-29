#include "Character.hpp"

Character::Character(): _name("default"){
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &copy) : _name(copy._name){
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy.inventory[i] != NULL) {
			this->inventory[i] = copy.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
}

Character::Character(std::string const &name): _name(name) {
	std::cout << "Character constructor with name" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character() {
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			//delete this->inventory[i];
		}
	}
}

Character &Character::operator=(Character const &rhs) {
	std::cout << "Character assignation operator" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != NULL) {
				delete this->inventory[i];
			}
			if (rhs.inventory[i] != NULL) {
				this->inventory[i] = rhs.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	std::cout << "Character equip" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	std::cout << "Character unequip" << std::endl;
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	std::cout << "Character use" << std::endl;
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return;

	this->inventory[idx]->use(target);
}