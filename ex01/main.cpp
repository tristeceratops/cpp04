#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    const int size = 10;
    Animal* animals[size];
    Animal* copiedAnimals[size];
    // Fill half with Dog objects
    std::cout << "\033[31mdog\033[0m" << std::endl << std::endl;
    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }
    // Fill the other half with Cat objects
    std::cout << "\033[31mcat\033[0m" << std::endl << std::endl;
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }
    std::cout << "\033[31mcopy\033[0m" << std::endl << std::endl;
	for (int i = 0; i < size; i++){
		copiedAnimals[i] = animals[i];
	}
	delete animals[0];
	animals[0] = new Dog();
    //Delete all animals
    std::cout << "\033[31mdelete\033[0m" << std::endl << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
		delete copiedAnimals[i];
    }
    return 0;
}