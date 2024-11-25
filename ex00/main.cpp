#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

void testAnimal() {
	std::cout << "\033[31mTesting Animal class:\033[0m" << std::endl;
    Animal a;
    Animal b(a);
    Animal c;
    c = a;
    std::cout << a.getType() << " is type" << std::endl;
    a.makeSound();
    b.makeSound();
    c.makeSound();
    std::cout << "\033[31mAnimal tests completed.\033[0m" << std::endl << std::endl;
}

void testDog() {
    std::cout << "\033[31mTesting Dog class:\033[0m" << std::endl;
    Dog d;
    Dog e(d);
    Dog f;
    f = d;
    std::cout << d.getType() << " is type" << std::endl;
    d.makeSound();
    e.makeSound();
    f.makeSound();
    std::cout << "\033[31mDog tests completed.\033[0m" << std::endl << std::endl;
}

void testCat() {
    std::cout << "\033[31mTesting Cat class:\033[0m" << std::endl;
    Cat g;
    Cat h(g);
    Cat i;
    i = g;
    std::cout << g.getType() << " is type" << std::endl;
    g.makeSound();
    h.makeSound();
    i.makeSound();
    std::cout << "\033[31mCat tests completed.\033[0m" << std::endl << std::endl;
}

void testPolymorphism() {
    std::cout << "\033[31mTesting Polymorphism:\033[0m" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " is type" << std::endl;
    std::cout << i->getType() << " is type" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output the animal sound!
    delete i;
    i = j;
    std::cout << i->getType() << " is type" << std::endl;
    i->makeSound();
    Dog* k = new Dog(*dynamic_cast<const Dog*>(j));
    std::cout << k->getType() << " is type" << std::endl;
    k->makeSound();
    delete meta;
    delete k;
    delete j;
    std::cout << "\033[31mPolymorphism tests completed.\033[0m" << std::endl << std::endl;
}

void testWrong() {
	std::cout << "\033[31mTesting WrongCat class:\033[0m" << std::endl;
    WrongCat g;
    WrongCat h(g);
    WrongCat i;
    i = g;
    std::cout << g.getType() << " is type" << std::endl;
    g.makeSound();
    h.makeSound();
    i.makeSound();
	const WrongAnimal *cat = new WrongCat();
    std::cout << cat->getType() << " is type" << std::endl;
    cat->makeSound();
	delete cat;
	std::cout << "\033[31mWrongCat tests completed.\033[0m" << std::endl << std::endl;
}

int main() {
    testAnimal();
    testDog();
    testCat();
    testPolymorphism();
    testWrong();
	return 0;
}