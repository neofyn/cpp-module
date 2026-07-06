/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/06 22:42:49 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * @brief Test that abstract Animal still supports polymorphism.
 *
 * Animal cannot be instantiated directly, but Animal pointers can still point
 * to Dog and Cat objects. Because makeSound() is virtual, the correct derived
 * function is called.
 */
static void	testAbstractPolymorphism(void)
{
	std::cout << "\n=== Abstract polymorphism test ===" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}

/**
 * @brief Test an array of abstract base pointers.
 *
 * The array stores Animal pointers, but every actual object is either a Dog
 * or a Cat. This proves Animal is still useful as a polymorphic interface.
 */
static void	testAnimalArray(void)
{
	std::cout << "\n=== Animal array test ===" << std::endl;
	Animal* animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 10; i++)
		delete animals[i];
}

/**
 * @brief Test deep copy behavior from ex01.
 *
 * ex02 should preserve the deep copy behavior introduced in ex01.
 */
static void	testDeepCopyStillWorks(void)
{
	std::cout << "\n=== Deep copy test ===" << std::endl;

	Dog basic;
	basic.setIdea(0, "I want a bone");

	{
		Dog copy(basic);

		std::cout << "basic idea before change: "
				  << basic.getIdea(0) << std::endl;
		std::cout << "copy idea before change:  "
				  << copy.getIdea(0) << std::endl;

		copy.setIdea(0, "I want to chase a cat");

		std::cout << "basic idea after change:  "
				  << basic.getIdea(0) << std::endl;
		std::cout << "copy idea after change:   "
				  << copy.getIdea(0) << std::endl;
	}

	std::cout << "basic idea after copy died: "
			  << basic.getIdea(0) << std::endl;
}

/**
 * @brief Test the old WrongAnimal behavior.
 *
 * WrongAnimal is not the main point of ex02, but keeping this test proves
 * that the previous exercise behavior still exists.
 */
static void	testWrongPolymorphism(void)
{
	std::cout << "\n=== Wrong polymorphism reminder ===" << std::endl;

	WrongCat wrongCat;
	WrongAnimal* wrongAnimal = &wrongCat;

	wrongCat.makeSound();
	wrongAnimal->makeSound();
}

/**
 * @brief Program entry point.
 *
 * Runs tests for abstract Animal polymorphism, array deletion, deep copy, and
 * the previous WrongAnimal behavior.
 *
 * @return Always returns 0.
 */
int	main(void)
{
	testAbstractPolymorphism();
	testAnimalArray();
	testDeepCopyStillWorks();
	testWrongPolymorphism();

	// Uncommenting either line below must fail compilation:
	// Animal animal;
	// const Animal* meta = new Animal();

	return (0);
}
