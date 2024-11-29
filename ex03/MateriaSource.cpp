#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.materias[i] != NULL){
			// this->materias[i] = other.materias[i];
			this->materias[i] = other.materias[i]->clone();
		}
		else {
			this->materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource assignation operator" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] != NULL) {
			delete this->materias[i];
		}
		if (other.materias[i] != NULL) {
			//this->materias[i] = other.materias[i];
			this->materias[i] = other.materias[i]->clone();
		}
		else
			this->materias[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] != NULL) {
			delete this->materias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	std::cout << "MateriaSource learnMateria" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = materia;
			std::cout << "learnmateria return create for i =" << i << "and type = " << this->materias[i]->getType() << std::endl;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	std::cout << "MateriaSource createMateria" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] != NULL && this->materias[i]->getType() == type) {
			std::cout << "createMateria return matieria for i =" << i << "and type = " << this->materias[i]->getType() << std::endl;
			return this->materias[i]->clone();
		}
	}
	std::cout << "createMateria return NULL" << std::endl;
	return NULL;
}