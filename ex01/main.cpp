#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
	const int size = 10;
	Animal *animals[size];
	Animal *copieAnimal[size];

	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++) {
		std::cout << animals[i]->getType() << " makes a sound: ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < size; i++) {
		copieAnimal[i] = animals[i]->clone();
	}
	Dog dog = *(Dog *)copieAnimal[0];
	dog.getBrain()->setIdea(0, "I am a dog");
	{
		Dog tmp;
		tmp = dog;
		std::cout << "Tmp Dog idea: " << tmp.getBrain()->getIdea(0) << std::endl;
		tmp.getBrain()->setIdea(0, "I am a good dog");
		std::cout << "Tmp Dog idea: " << tmp.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "Dog idea: " << dog.getBrain()->getIdea(0) << std::endl;

	copieAnimal[0]->makeSound();

	for (int i = 0; i < size; i++) {
		delete animals[i];
		delete copieAnimal[i];
	}

	return 0;
}