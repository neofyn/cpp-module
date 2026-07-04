/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:02:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 14:40:12 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/**
 * @class Fixed
 * @brief Represents a fixed-point number with 8 fractional bits.
 *
 * The value is stored internally as an integer. The real represented value is:
 *
 * rawBits / 2^fractionalBits
 *
 * For this exercise, fractionalBits is always 8, so the scale is 256.
 */
class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		/**
		 * @brief Default constructor.
		 *
		 * Initializes the fixed-point value to 0.
		 */
		Fixed(void);

		/**
		 * @brief Integer constructor.
		 *
		 * Converts an integer to fixed-point representation.
		 *
		 * @param value Integer value to convert.
		 */
		Fixed(int const value);

		/**
		 * @brief Float constructor.
		 *
		 * Converts a floating-point value to fixed-point representation.
		 *
		 * @param value Floating-point value to convert.
		 */
		Fixed(float const value);

		/**
		 * @brief Copy constructor.
		 *
		 * Creates a new Fixed object from another Fixed object.
		 *
		 * @param other Object to copy.
		 */
		Fixed(Fixed const &other);

		/**
		 * @brief Copy assignment operator.
		 *
		 * Copies the raw value from another existing Fixed object.
		 *
		 * @param other Object to copy from.
		 * @return Reference to the current object.
		 */
		Fixed &operator=(Fixed const &other);

		/**
		 * @brief Destructor.
		 */
		~Fixed(void);

		/**
		 * @brief Get the raw fixed-point value.
		 *
		 * @return Internal raw integer value.
		 */
		int getRawBits(void) const;

		/**
		 * @brief Set the raw fixed-point value.
		 *
		 * @param raw New raw integer value.
		 */
		void setRawBits(int const raw);

		/**
		 * @brief Convert the fixed-point value to float.
		 *
		 * @return Floating-point representation.
		 */
		float toFloat(void) const;

		/**
		 * @brief Convert the fixed-point value to int.
		 *
		 * @return Integer representation.
		 */
		int toInt(void) const;
};

/**
 * @brief Insert a Fixed number into an output stream.
 *
 * Prints the Fixed object as a floating-point number.
 *
 * @param out Output stream.
 * @param fixed Fixed object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif