/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:32:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief Default constructor.
 */
Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
Dog::Dog(const Dog& other) : Animal(other)
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
		Animal::operator=(other);
	return (*this);
}

/**
 * @brief Destructor.
 */
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

/**
 * @brief Print the dog sound.
 */
void Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}
