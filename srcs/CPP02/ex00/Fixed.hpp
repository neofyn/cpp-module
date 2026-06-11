/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:02:19 by fyudris           #+#    #+#             */
/*   Updated: 2026/04/08 19:17:52 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int					_rawBits; // To store fixed-point value

		// The static keyword means this variable is shared by `all` instances of the class. Every `Fixed` number will have 8 fractional bits.
		static const int	_fractionalBits = 8; // Constant set to 8

		public:
		// --- Orthodox Canonical Form ---
			Fixed(); // Default constructor
			Fixed(const Fixed &other); // Copy constructor
			Fixed &operator=(const Fixed &other); // Copy assignment operator
			~Fixed();

			// --- Other member functions ---
			int getRawBits(void) const; // Returns the raw value
			void setRawBits(int const raw); // Sets the raw value
}

#endif
