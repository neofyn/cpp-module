/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/06 22:36:29 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

/**
 * @class Animal
 * @brief Base class used to demonstrate runtime polymorphism.
 *
 * Animal stores a protected type string and exposes a virtual makeSound()
 * function. Because makeSound() is virtual, calling it through an Animal*
 * will execute the derived class version when the real object is a Dog or Cat.
 */
class Animal
{
protected:
	std::string type;

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the animal type to a generic value.
	 */
	Animal(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Copies the type from another Animal.
	 *
	 * @param other Animal object to copy from.
	 */
	Animal(const Animal& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies the type from another Animal if this object is not assigning
	 * itself.
	 *
	 * @param other Animal object to assign from.
	 * @return Reference to the current Animal object.
	 */
	Animal& operator=(const Animal& other);

	/**
	 * @brief Virtual destructor.
	 *
	 * Must be virtual because Animal is used as a polymorphic base class.
	 * This allows deleting Dog or Cat objects safely through Animal pointers.
	 */
	virtual ~Animal(void);

	/**
	 * @brief Get the animal type.
	 *
	 * @return The type stored inside the Animal.
	 */
	std::string getType(void) const;

	/**
	 * @brief Print the generic animal sound.
	 *
	 * This function is virtual so derived classes can override it.
	 */
	virtual void makeSound(void) const;
};

#endif
