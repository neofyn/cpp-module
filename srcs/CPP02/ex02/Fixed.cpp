/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:54:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 18:13:34 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/**
 * @brief Default constructor.
 */
Fixed::Fixed(void) : _rawBits(0)
{
}

/**
 * @brief Integer constructor.
 *
 * Example:
 * value = 2
 * _rawBits = 2 * 256 = 512
 */
Fixed::Fixed(const int value)
{
	this->_rawBits = value << _fractionalBits;
}

/**
 * @brief Float constructor.
 *
 * Example:
 * value = 5.05
 * _rawBits = roundf(5.05 * 256)
 */
Fixed::Fixed(const float value)
{
	this->_rawBits = roundf(value * (1 << _fractionalBits));
}

/**
 * @brief Copy constructor.
 */
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
}

/**
 * @brief Copy assignment operator.
 */
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_rawBits = other._rawBits;
	return (*this);
}

/**
 * @brief Destructor.
 */
Fixed::~Fixed(void)
{
}

/**
 * @brief Greater-than comparison.
 */
bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_rawBits > rhs._rawBits);
}

/**
 * @brief Less-than comparison.
 */
bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_rawBits < rhs._rawBits);
}

/**
 * @brief Greater-than-or-equal comparison.
 */
bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_rawBits >= rhs._rawBits);
}

/**
 * @brief Less-than-or-equal comparison.
 */
bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_rawBits <= rhs._rawBits);
}

/**
 * @brief Equality comparison.
 */
bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_rawBits == rhs._rawBits);
}

/**
 * @brief Inequality comparison.
 */
bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_rawBits != rhs._rawBits);
}

/**
 * @brief Add two fixed-point numbers.
 *
 * Addition can be done directly on raw values because both numbers use
 * the same scale factor.
 */
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;

	result.setRawBits(this->_rawBits + rhs._rawBits);
	return (result);
}

/**
 * @brief Subtract two fixed-point numbers.
 *
 * Subtraction can be done directly on raw values because both numbers use
 * the same scale factor.
 */
Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;

	result.setRawBits(this->_rawBits - rhs._rawBits);
	return (result);
}

/**
 * @brief Multiply two fixed-point numbers.
 *
 * Raw multiplication scales the result twice, so the product must be divided
 * once by the scale factor.
 */
Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;
	long	product;

	product = static_cast<long>(this->_rawBits)
		* static_cast<long>(rhs._rawBits);
	result.setRawBits(static_cast<int>(product / (1 << _fractionalBits)));
	return (result);
}

/**
 * @brief Divide two fixed-point numbers.
 *
 * The numerator is scaled before division so the result keeps fixed-point
 * precision.
 */
Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result;
	long	numerator;

	numerator = static_cast<long>(this->_rawBits) * (1 << _fractionalBits);
	result.setRawBits(static_cast<int>(numerator / rhs._rawBits));
	return (result);
}

/**
 * @brief Pre-increment.
 *
 * Increases the raw value by 1.
 */
Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

/**
 * @brief Post-increment.
 *
 * Saves the old value, increments the current object, then returns the old value.
 */
Fixed Fixed::operator++(int)
{
	Fixed old(*this);

	++(*this);
	return (old);
}

/**
 * @brief Pre-decrement.
 *
 * Decreases the raw value by 1.
 */
Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

/**
 * @brief Post-decrement.
 *
 * Saves the old value, decrements the current object, then returns the old value.
 */
Fixed Fixed::operator--(int)
{
	Fixed old(*this);

	--(*this);
	return (old);
}

/**
 * @brief Get the internal raw value.
 */
int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

/**
 * @brief Set the internal raw value.
 */
void Fixed::setRawBits(const int raw)
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
 * @brief Return the smaller of two non-const Fixed objects.
 */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

/**
 * @brief Return the smaller of two const Fixed objects.
 */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

/**
 * @brief Return the greater of two non-const Fixed objects.
 */
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

/**
 * @brief Return the greater of two const Fixed objects.
 */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

/**
 * @brief Print Fixed as a float.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
