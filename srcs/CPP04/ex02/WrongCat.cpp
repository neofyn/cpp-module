/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:36:20 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/**
 * @brief Default constructor.
 */
WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/**
 * @brief Copy assignment operator.
 */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

/**
 * @brief Destructor.
 */
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/**
 * @brief Print the wrong cat sound.
 */
void WrongCat::makeSound(void) const
{
	std::cout << "Wrong meow meow!" << std::endl;
}
