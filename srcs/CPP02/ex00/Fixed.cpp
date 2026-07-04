/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:54:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 13:54:29 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Default constructor.
 *
 * Initializes the internal raw fixed-point value to 0.
 */
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 *
 * Builds a new Fixed object from another Fixed object.
 * This implementation reuses the copy assignment operator to keep the copy
 * logic in one place.
 *
 * @param other The Fixed object to copy.
 */
Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator.
 *
 * Copies the raw value from another Fixed object into the current object.
 * The self-assignment check protects against cases like:
 *
 * @code
 * a = a;
 * @endcode
 *
 * @param other The Fixed object to assign from.
 * @return A reference to the current object.
 */
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

/**
 * @brief Destructor.
 *
 * Called automatically when a Fixed object is destroyed.
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Return the raw fixed-point value.
 *
 * @return The internal raw integer value.
 */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

/**
 * @brief Set the raw fixed-point value.
 *
 * @param raw The new raw integer value.
 */
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}