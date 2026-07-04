/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:36:26 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * @brief Test correct runtime polymorphism.
 *
 * Dog and Cat are stored as Animal pointers. Because Animal::makeSound()
 * is virtual, the Dog and Cat sound functions are called.
 */
static void	testCorrectPolymorphism(void)
{
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << "\n=== Correct polymorphism test ===" << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;
}

/**
 * @brief Test direct object calls.
 *
 * This test shows that direct Dog and Cat objects also call their own
 * makeSound() functions.
 */
static void	testDirectObjects(void)
{
	Dog	dog;
	Cat	cat;

	std::cout << "\n=== Direct object test ===" << std::endl;

	std::cout << dog.getType() << std::endl;
	dog.makeSound();

	std::cout << cat.getType() << std::endl;
	cat.makeSound();
}

/**
 * @brief Test copy constructor and copy assignment behavior.
 *
 * In ex00, Dog and Cat do not own dynamic resources yet. Their copy behavior
 * simply reuses the Animal copy logic.
 */
static void	testCopies(void)
{
	Dog	originalDog;
	Dog	copiedDog(originalDog);
	Cat	originalCat;
	Cat	assignedCat;

	std::cout << "\n=== Copy test ===" << std::endl;

	assignedCat = originalCat;

	std::cout << copiedDog.getType() << std::endl;
	copiedDog.makeSound();

	std::cout << assignedCat.getType() << std::endl;
	assignedCat.makeSound();
}

/**
 * @brief Test wrong polymorphism.
 *
 * WrongAnimal::makeSound() is not virtual. Therefore, calling makeSound()
 * through a WrongAnimal pointer calls WrongAnimal::makeSound(), even when
 * the real object is a WrongCat.
 */
static void	testWrongPolymorphism(void)
{
	WrongAnimal	wrongAnimal;
	WrongCat	wrongCat;
	WrongAnimal*	wrongPointer = &wrongCat;

	std::cout << "\n=== Wrong polymorphism test ===" << std::endl;

	std::cout << wrongAnimal.getType() << std::endl;
	wrongAnimal.makeSound();

	std::cout << wrongCat.getType() << std::endl;
	wrongCat.makeSound();

	std::cout << "Calling WrongCat through WrongAnimal pointer:" << std::endl;
	wrongPointer->makeSound();
}

/**
 * @brief Program entry point.
 *
 * Runs all tests required to demonstrate CPP04 ex00 behavior.
 *
 * @return Always returns 0.
 */
int	main(void)
{
	testCorrectPolymorphism();
	testDirectObjects();
	testCopies();
	testWrongPolymorphism();
	return (0);
}
