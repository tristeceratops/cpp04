#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materiaCount(0) {
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
	for (int i = 0; i < 100; i++) {
		this->allMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : materiaCount(other.materiaCount) {
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.materias[i] != NULL){
			this->materias[i] = other.materias[i]->clone();
		}
		else {
			this->materias[i] = NULL;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (other.allMaterias[i] != NULL) {
			this->allMaterias[i] = other.allMaterias[i]->clone();
		} else {
			this->allMaterias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource assignation operator" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->materias[i] != NULL) {
				delete this->materias[i];
			}
			if (other.materias[i] != NULL) {
				this->materias[i] = other.materias[i]->clone();
			}
			else {
				this->materias[i] = NULL;
			}
		}
		for (int i = 0; i < 100; i++) {
			if (this->allMaterias[i] != NULL) {
				delete this->allMaterias[i];
			}
			if (other.allMaterias[i] != NULL) {
				this->allMaterias[i] = other.allMaterias[i]->clone();
			} else {
				this->allMaterias[i] = NULL;
			}
		}
		this->materiaCount = other.materiaCount;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor" << std::endl;
	// Clear the materias array to avoid double deletion
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
	// Delete all allocated materias
	for (int i = 0; i < 100; i++) {
		if (this->allMaterias[i] != NULL) {
			delete this->allMaterias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	std::cout << "MateriaSource learnMateria" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = materia;
			this->allMaterias[materiaCount++] = materia; // Track the allocated materia
			return;
		}
	}
	// If the materias array is full, still track the allocated materia
	this->allMaterias[materiaCount++] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	std::cout << "MateriaSource createMateria" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i] != NULL && this->materias[i]->getType() == type) {
			return this->materias[i];
		}
	}
	return NULL;
}