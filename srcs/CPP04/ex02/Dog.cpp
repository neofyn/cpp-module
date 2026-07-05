/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:40:43 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief Default constructor.
 */
Dog::Dog(void) : Animal(), brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * @brief Copy assignment operator.
 */
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);

		Brain* newBrain = new Brain(*other.brain);
		delete this->brain;
		this->brain = newBrain;
	}
	return (*this);
}

/**
 * @brief Destructor.
 */
Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

/**
 * @brief Print the dog sound.
 */
void Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}

/**
 * @brief Set one idea inside the Dog's Brain.
 */
void Dog::setIdea(int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}

/**
 * @brief Get one idea from the Dog's Brain.
 */
std::string Dog::getIdea(int index) const
{
	return (this->brain->getIdea(index));
}
