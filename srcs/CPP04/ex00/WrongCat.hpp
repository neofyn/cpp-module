/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:36:15 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/**
 * @class WrongCat
 * @brief Derived class used to demonstrate missing virtual dispatch.
 *
 * WrongCat has its own makeSound(), but when accessed through WrongAnimal*,
 * WrongAnimal::makeSound() will be called because the base function is not
 * virtual.
 */
class WrongCat : public WrongAnimal
{
public:
	/**
	 * @brief Default constructor.
	 */
	WrongCat(void);

	/**
	 * @brief Copy constructor.
	 *
	 * @param other WrongCat object to copy from.
	 */
	WrongCat(const WrongCat& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * @param other WrongCat object to assign from.
	 * @return Reference to the current WrongCat object.
	 */
	WrongCat& operator=(const WrongCat& other);

	/**
	 * @brief Destructor.
	 */
	~WrongCat(void);

	/**
	 * @brief Print the wrong cat sound.
	 *
	 * This function exists, but it will not be called through WrongAnimal*.
	 */
	void makeSound(void) const;
};

#endif
