#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
	const int size = 6;
	Dog * dogs[size];
	Cat * cats[size];

	for (int i = 0; i < size; i++) {
			dogs[i] = new Dog();
	}

	for (int i = 0; i < size; i++) {
			cats[i] = new Cat();
	}

	for (int i = 0; i < size; i++) {
		std::cout << dogs[i]->getType() << " makes a sound: ";
		dogs[i]->makeSound();
		std::cout << cats[i]->getType() << " makes a sound: ";
		cats[i]->makeSound();
	}

	for (int i = 0; i < size; i++) {
		delete dogs[i];
		delete cats[i];
	}

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase the ball");
	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Climb the tree");

	Dog copyDog(originalDog);
	Cat copyCat(originalCat);


	std::cout << "Original Dog Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "    Copy Dog Idea: " << copyDog.getBrain()->getIdea(0) << std::endl << std::endl;

	std::cout << "Original Cat Idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "    Copy Cat Idea: " << copyCat.getBrain()->getIdea(0) << std::endl;

	originalDog.getBrain()->setIdea(0, "Sleep all day");
	copyCat.getBrain()->setIdea(0, "Chase mice");

	std::cout << "After changing copyDog, Original Dog Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "After changing copyDog,  CopyDog Dog Idea: " << copyDog.getBrain()->getIdea(0) << std::endl << std::endl;
	std::cout << "After changing copyCat, Original Cat Idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "After changing copyCat,  CopyCat Cat Idea: " << copyCat.getBrain()->getIdea(0) << std::endl;


	return 0;
}