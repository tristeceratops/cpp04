#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main() {

	std::cout << RED << std::endl;

	const int size = 10;
	Animal *animals[size];

	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << GREEN << std::endl;

	for (int i = 0; i < size; i++) {
		std::cout << animals[i]->getType() << " makes a sound: ";
		animals[i]->makeSound();
	}

	std::cout << YELLOW << std::endl;

	Dog dog = *(Dog *)animals[0];


	dog.getBrain()->setIdea(0, "I am a dog");
	{
		Dog tmp;
		tmp = dog;
		std::cout << "Tmp Dog idea: " << tmp.getBrain()->getIdea(0) << std::endl;
		tmp.getBrain()->setIdea(0, "I am a good dog");
		std::cout << "Tmp Dog idea: " << tmp.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "Dog idea: " << dog.getBrain()->getIdea(0) << std::endl;

	std::cout << BLUE << std::endl;

	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
	std::cout << RESET << std::endl;

	return 0;
}