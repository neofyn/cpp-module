/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 23:34:18 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

/**
 * @class Animal
 * @brief Abstract base class for animal types.
 *
 * Animal stores a common type string and defines the shared interface for all
 * derived animals. Because makeSound() is pure virtual, Animal cannot be
 * instantiated directly. Only concrete derived classes such as Dog and Cat can
 * be created.
 */
class Animal
{
protected:
	std::string type;

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the base Animal part of a derived object.
	 */
	Animal(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Copies the base Animal part from another Animal object.
	 *
	 * @param other Animal object to copy from.
	 */
	Animal(const Animal& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies the type string from another Animal object.
	 *
	 * @param other Animal object to assign from.
	 * @return Reference to the current Animal object.
	 */
	Animal& operator=(const Animal& other);

	/**
	 * @brief Virtual destructor.
	 *
	 * Must be virtual because Animal is used as a polymorphic base class.
	 * This allows Dog and Cat destructors to run correctly when deleting
	 * through an Animal pointer.
	 */
	virtual ~Animal(void);

	/**
	 * @brief Get the animal type.
	 *
	 * @return The type string stored in the Animal base part.
	 */
	std::string getType(void) const;

	/**
	 * @brief Pure virtual sound function.
	 *
	 * This makes Animal abstract. Every concrete derived class must implement
	 * this function.
	 */
	virtual void makeSound(void) const = 0;
};

#endif
