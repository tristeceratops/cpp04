#include "Character.hpp"

Character::Character(): head(NULL), _name("default"), inv_index(0) {
    //std::cout << "Character default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const &copy) : head(NULL), _name(copy._name), inv_index(copy.inv_index) {
    //std::cout << "Character copy constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (copy.inventory[i] != NULL) {
            this->inventory[i] = copy.inventory[i]->clone();
        } else {
            this->inventory[i] = NULL;
        }
    }
    copyList(copy);
}

Character::Character(std::string const &name): head(NULL), _name(name), inv_index(0){
    //std::cout << "Character constructor with name" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::~Character() {
    std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    clearList();
}

Character &Character::operator=(Character const &rhs) {
    //std::cout << "Character assignation operator" << std::endl;
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
        clearList();
        copyList(rhs);
    }
    return *this;
}

std::string const &Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria *m) {
    //std::cout << "Character equip" << std::endl;
    if (m == NULL)
        return;
    AMateria* clone = m->clone();
    if (inv_index < 4) {
        this->inventory[inv_index++] = clone;
    } else {
        Node* newNode = new Node(clone);
        newNode->next = head;
        head = newNode;
    }
}

void Character::unequip(int idx) {
    //std::cout << "Character unequip" << std::endl;
    if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
        return;
    Node* newNode = new Node(this->inventory[idx]);
    newNode->next = head;
    head = newNode;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    //std::cout << "Character use" << std::endl;
    if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
        return;

    this->inventory[idx]->use(target);
}

void Character::clearList() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
    head = NULL;
}

void Character::copyList(const Character &other) {
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