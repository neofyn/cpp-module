/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:41:05 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief Default constructor.
 */
Cat::Cat(void) : Animal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/**
 * @brief Copy assignment operator.
 */
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
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
Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Print the cat sound.
 */
void Cat::makeSound(void) const
{
	std::cout << "Meow meow!" << std::endl;
}

/**
 * @brief Set one idea inside the Cat's Brain.
 */
void Cat::setIdea(int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}

/**
 * @brief Get one idea from the Cat's Brain.
 */
std::string Cat::getIdea(int index) const
{
	return (this->brain->getIdea(index));
}
