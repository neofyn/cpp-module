/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:31:43 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

/**
 * @class Dog
 * @brief Derived Animal class representing a dog.
 *
 * Dog sets the inherited type field to "Dog" and overrides makeSound().
 */
class Dog : public Animal
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the inherited type field to "Dog".
	 */
	Dog(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Copies the Animal part from another Dog.
	 *
	 * @param other Dog object to copy from.
	 */
	Dog(const Dog& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Reuses Animal's assignment operator because Dog has no extra attributes.
	 *
	 * @param other Dog object to assign from.
	 * @return Reference to the current Dog object.
	 */
	Dog& operator=(const Dog& other);

	/**
	 * @brief Destructor.
	 */
	virtual ~Dog(void);

	/**
	 * @brief Print the dog sound.
	 */
	void makeSound(void) const;
};

#endif
