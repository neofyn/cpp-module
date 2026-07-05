/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:02:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 19:11:51 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/**
 * @class Fixed
 * @brief Represents a fixed-point number in Orthodox Canonical Form.
 *
 * In exercise 00, the class only stores the raw fixed-point value.
 * The fractional bit count is required by the subject.
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
		 * Initializes the raw fixed-point value to 0.
		 */
		Fixed(void);

		/**
		 * @brief Copy constructor.
		 *
		 * Creates a new Fixed object as a copy of another Fixed object.
		 *
		 * @param other The Fixed object to copy from.
		 */
		Fixed(const Fixed &other);

		/**
		 * @brief Copy assignment operator.
		 *
		 * Copies the raw value from another already-existing Fixed object.
		 *
		 * @param other The Fixed object to assign from.
		 * @return A reference to the current object.
		 */
		Fixed &operator=(const Fixed &other);

		/**
		 * @brief Destructor.
		 *
		 * Called when a Fixed object goes out of scope.
		 */
		~Fixed(void);

		/**
		 * @brief Get the raw fixed-point value.
		 *
		 * @return The internal raw integer value.
		 */
		int getRawBits(void) const;

		/**
		 * @brief Set the raw fixed-point value.
		 *
		 * @param raw The new raw integer value.
		 */
		void setRawBits(const int raw);
};

#endif
