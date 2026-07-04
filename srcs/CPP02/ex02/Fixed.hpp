/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:02:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 18:13:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/**
 * @class Fixed
 * @brief Fixed-point number class with 8 fractional bits.
 *
 * The value is stored internally as an integer.
 *
 * Real value = _rawBits / 2^_fractionalBits
 *
 * Since _fractionalBits is 8, the scale factor is 256.
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
		Fixed(const int value);

		/**
		 * @brief Float constructor.
		 *
		 * Converts a floating-point number to fixed-point representation.
		 *
		 * @param value Floating-point value to convert.
		 */
		Fixed(const float value);

		/**
		 * @brief Copy constructor.
		 *
		 * Creates a new Fixed object from another Fixed object.
		 *
		 * @param other Object to copy.
		 */
		Fixed(const Fixed &other);

		/**
		 * @brief Copy assignment operator.
		 *
		 * Copies the raw value from another already-existing Fixed object.
		 *
		 * @param other Object to copy from.
		 * @return Reference to the current object.
		 */
		Fixed &operator=(const Fixed &other);

		/**
		 * @brief Destructor.
		 */
		~Fixed(void);

		/**
		 * @brief Greater-than comparison.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return true if this object is greater than rhs.
		 */
		bool operator>(const Fixed &rhs) const;

		/**
		 * @brief Less-than comparison.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return true if this object is less than rhs.
		 */
		bool operator<(const Fixed &rhs) const;

		/**
		 * @brief Greater-than-or-equal comparison.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return true if this object is greater than or equal to rhs.
		 */
		bool operator>=(const Fixed &rhs) const;

		/**
		 * @brief Less-than-or-equal comparison.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return true if this object is less than or equal to rhs.
		 */
		bool operator<=(const Fixed &rhs) const;

		/**
		 * @brief Equality comparison.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return true if both objects have the same raw value.
		 */
		bool operator==(const Fixed &rhs) const;

		/**
		 * @brief Inequality comparison.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return true if both objects have different raw values.
		 */
		bool operator!=(const Fixed &rhs) const;

		/**
		 * @brief Add two Fixed values.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return Sum as a new Fixed object.
		 */
		Fixed operator+(const Fixed &rhs) const;

		/**
		 * @brief Subtract two Fixed values.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return Difference as a new Fixed object.
		 */
		Fixed operator-(const Fixed &rhs) const;

		/**
		 * @brief Multiply two Fixed values.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return Product as a new Fixed object.
		 */
		Fixed operator*(const Fixed &rhs) const;

		/**
		 * @brief Divide two Fixed values.
		 *
		 * Division by zero is not protected because the subject accepts
		 * crashing in that case.
		 *
		 * @param rhs Right-hand side Fixed object.
		 * @return Quotient as a new Fixed object.
		 */
		Fixed operator/(const Fixed &rhs) const;

		/**
		 * @brief Pre-increment operator.
		 *
		 * Increases the raw value by 1, which is the smallest representable
		 * fixed-point step.
		 *
		 * @return Reference to the modified current object.
		 */
		Fixed &operator++(void);

		/**
		 * @brief Post-increment operator.
		 *
		 * Returns the old value, then increments the current object.
		 *
		 * @return Copy of the object before incrementing.
		 */
		Fixed operator++(int);

		/**
		 * @brief Pre-decrement operator.
		 *
		 * Decreases the raw value by 1.
		 *
		 * @return Reference to the modified current object.
		 */
		Fixed &operator--(void);

		/**
		 * @brief Post-decrement operator.
		 *
		 * Returns the old value, then decrements the current object.
		 *
		 * @return Copy of the object before decrementing.
		 */
		Fixed operator--(int);

		/**
		 * @brief Get the internal raw fixed-point value.
		 *
		 * @return Internal raw integer value.
		 */
		int getRawBits(void) const;

		/**
		 * @brief Set the internal raw fixed-point value.
		 *
		 * @param raw New raw integer value.
		 */
		void setRawBits(const int raw);

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

		/**
		 * @brief Return the smaller of two non-const Fixed objects.
		 *
		 * @param a First object.
		 * @param b Second object.
		 * @return Reference to the smaller object.
		 */
		static Fixed &min(Fixed &a, Fixed &b);

		/**
		 * @brief Return the smaller of two const Fixed objects.
		 *
		 * @param a First object.
		 * @param b Second object.
		 * @return Const reference to the smaller object.
		 */
		static const Fixed &min(const Fixed &a, const Fixed &b);

		/**
		 * @brief Return the greater of two non-const Fixed objects.
		 *
		 * @param a First object.
		 * @param b Second object.
		 * @return Reference to the greater object.
		 */
		static Fixed &max(Fixed &a, Fixed &b);

		/**
		 * @brief Return the greater of two const Fixed objects.
		 *
		 * @param a First object.
		 * @param b Second object.
		 * @return Const reference to the greater object.
		 */
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

/**
 * @brief Insert a Fixed object into an output stream.
 *
 * Prints the Fixed object as a floating-point number.
 *
 * @param out Output stream.
 * @param fixed Fixed object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
