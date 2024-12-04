#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : head(NULL), materiaCount(0) {
    //std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) : head(NULL), materiaCount(other.materiaCount) {
    // std::cout << "MateriaSource copy constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.materias[i] != NULL){
            this->materias[i] = other.materias[i]->clone();
        }
        else {
            this->materias[i] = NULL;
        }
    }
    copyList(other);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    // std::cout << "MateriaSource assignation operator" << std::endl;
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
        clearList();
        copyList(other);
        this->materiaCount = other.materiaCount;
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    //std::cout << "MateriaSource destructor" << std::endl;
    clearList();
}

void MateriaSource::learnMateria(AMateria *materia) {
    //std::cout << "MateriaSource learnMateria" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->materias[i] == NULL) {
            this->materias[i] = materia;
            Node* newNode = new Node(materia);
            newNode->next = head;
            head = newNode;
            materiaCount++;
            return;
        }
    }
    Node* newNode = new Node(materia);
    newNode->next = head;
    head = newNode;
    materiaCount++;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    //std::cout << "MateriaSource createMateria" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->materias[i] != NULL && this->materias[i]->getType() == type) {
            AMateria *a = this->materias[i]->clone();
            Node* newNode = new Node(a);
            newNode->next = head;
            head = newNode;
            materiaCount++;
            return a;
        }
    }
    return NULL;
}

void MateriaSource::clearList() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
    head = NULL;
}

void MateriaSource::copyList(const MateriaSource &other) {
    if (other.head == NULL) {
        head = NULL;
        return;
    }
    head = new Node(other.head->materia->clone());
    Node* current = head;
    Node* otherCurrent = other.head->next;
    while (otherCurrent != NULL) {
        current->next = new Node(otherCurrent->materia->clone());
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}