/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:33:18 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief Default constructor.
 */
Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
Cat::Cat(const Cat& other) : Animal(other)
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
		Animal::operator=(other);
	return (*this);
}

/**
 * @brief Destructor.
 */
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Print the cat sound.
 */
void Cat::makeSound(void) const
{
	std::cout << "Meow meow!" << std::endl;
}
