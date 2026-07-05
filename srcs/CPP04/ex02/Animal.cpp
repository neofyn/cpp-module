/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 23:34:37 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**
 * @brief Default constructor.
 */
Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 */
Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator.
 */
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/**
 * @brief Virtual destructor.
 */
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/**
 * @brief Get the animal type.
 */
std::string Animal::getType(void) const
{
	return (this->type);
}
