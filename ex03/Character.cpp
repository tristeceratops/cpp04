#include "Character.hpp"

Character::Character(): _name("default"), index(0) {
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->memory[i] = NULL;
}

Character::Character(Character const &copy) : _name(copy._name), index(copy.index){
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy.inventory[i] != NULL) {
			this->inventory[i] = copy.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (copy.memory[i] != NULL) {
			this->memory[i] = copy.memory[i]->clone();
		} else {
			this->memory[i] = NULL;
		}
	}
}

Character::Character(std::string const &name): _name(name), index(0) {
	std::cout << "Character constructor with name" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->memory[i] = NULL;
}

Character::~Character() {
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
	}

	for (int i = 0; i < 100; i++) {
		if (this->memory[i] != NULL) {
			delete this->memory[i];
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
		for (int i = 0; i < 100; i++) {
			if (this->memory[i] != NULL) {
				delete this->memory[i];
			}
			if (rhs.memory[i] != NULL) {
				this->memory[i] = rhs.memory[i]->clone();
			} else {
				this->memory[i] = NULL;
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
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			continue;
		this->inventory[i] = m->clone();
		break;
	}
	for (int j = 0; j < 100; j++) {
		if (this->memory[j] == NULL){
			this->memory[j] = m->clone();
			break;
		}
	}
	return;

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