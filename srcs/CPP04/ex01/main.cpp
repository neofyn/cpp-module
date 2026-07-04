/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:41:20 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * @brief Test the small example from the subject.
 *
 * Dog and Cat are created through Animal pointers and deleted through Animal
 * pointers. This checks that makeSound() and destructors are virtual.
 */
static void	testSubjectExample(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n=== Subject leak test ===" << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}

/**
 * @brief Test deleting an array of Animals.
 *
 * The array stores Dog and Cat objects as Animal pointers. Deleting each item
 * through Animal* must call the correct derived destructor.
 */
static void	testAnimalArray(void)
{
	Animal*	animals[10];

	std::cout << "\n=== Animal array test ===" << std::endl;

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
 * @brief Test deep copy using the Dog copy constructor.
 *
 * If the copy is shallow, tmp and basic share the same Brain. When tmp dies,
 * basic would point to deleted memory. With a deep copy, basic remains safe.
 */
static void	testDogCopyConstructor(void)
{
	std::cout << "\n=== Dog copy constructor deep copy test ===" << std::endl;

	Dog basic;
	basic.setIdea(0, "I want a bone");

	{
		Dog tmp(basic);

		std::cout << "basic idea before tmp change: "
				  << basic.getIdea(0) << std::endl;
		std::cout << "tmp idea before tmp change:    "
				  << tmp.getIdea(0) << std::endl;

		tmp.setIdea(0, "I want to chase the mailman");

		std::cout << "basic idea after tmp change:  "
				  << basic.getIdea(0) << std::endl;
		std::cout << "tmp idea after tmp change:     "
				  << tmp.getIdea(0) << std::endl;
	}

	std::cout << "basic idea after tmp died:     "
			  << basic.getIdea(0) << std::endl;
}

/**
 * @brief Test deep copy using the Cat assignment operator.
 *
 * This test proves that after assignment, changing one Cat's Brain does not
 * change the other Cat's Brain.
 */
static void	testCatAssignment(void)
{
	std::cout << "\n=== Cat assignment deep copy test ===" << std::endl;

	Cat original;
	Cat assigned;

	original.setIdea(0, "I want fish");
	assigned = original;

	std::cout << "original idea before change: "
			  << original.getIdea(0) << std::endl;
	std::cout << "assigned idea before change: "
			  << assigned.getIdea(0) << std::endl;

	assigned.setIdea(0, "I want to knock a glass off the table");

	std::cout << "original idea after change:  "
			  << original.getIdea(0) << std::endl;
	std::cout << "assigned idea after change:  "
			  << assigned.getIdea(0) << std::endl;
}

/**
 * @brief Test the previous wrong-polymorphism example.
 *
 * WrongAnimal::makeSound() is not virtual, so calling through WrongAnimal*
 * calls the WrongAnimal version.
 */
static void	testWrongPolymorphism(void)
{
	std::cout << "\n=== Wrong polymorphism reminder test ===" << std::endl;

	WrongCat wrongCat;
	WrongAnimal* wrongAnimal = &wrongCat;

	wrongCat.makeSound();
	wrongAnimal->makeSound();
}

/**
 * @brief Program entry point.
 *
 * Runs all ex01 tests: subject example, polymorphic deletion, array deletion,
 * deep copy construction, deep copy assignment, and wrong polymorphism.
 *
 * @return Always returns 0.
 */
int	main(void)
{
	testSubjectExample();
	testAnimalArray();
	testDogCopyConstructor();
	testCatAssignment();
	testWrongPolymorphism();
	return (0);
}
