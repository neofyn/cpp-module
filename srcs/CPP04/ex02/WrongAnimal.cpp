/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:34:10 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/**
 * @brief Default constructor.
 */
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator.
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/**
 * @brief Destructor.
 */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/**
 * @brief Get the wrong animal type.
 */
std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

/**
 * @brief Print the wrong animal sound.
 */
void WrongAnimal::makeSound(void) const
{
	std::cout << "Some wrong generic animal sound" << std::endl;
}
