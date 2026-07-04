/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:54:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 14:44:40 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/**
 * @brief Default constructor.
 */
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Integer constructor.
 *
 * Example:
 * value = 10
 * rawBits = 10 * 256 = 2560
 */
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << _fractionalBits;
}

/**
 * @brief Float constructor.
 *
 * Example:
 * value = 42.42
 * rawBits = roundf(42.42 * 256)
 * 
 * Normally = 10859.52, and truncated to 10859 to be stored as int
 * roundf() gives a more accurate gied-point representation and 
 * correct rounding to 10860.
 * 
 *  
 */
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << _fractionalBits));
}

/**
 * @brief Copy constructor.
 *
 * Reuses the assignment operator so the copying logic stays in one place.
 */
Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator.
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
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Return the internal raw value.
 */
int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

/**
 * @brief Set the internal raw value.
 */
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

/**
 * @brief Convert fixed-point value to float.
 */
float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << _fractionalBits));
}

/**
 * @brief Convert fixed-point value to int.
 */
int Fixed::toInt(void) const
{
	return (this->_rawBits >> _fractionalBits);
}

/**
 * @brief Print Fixed as a float.
 */
std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}