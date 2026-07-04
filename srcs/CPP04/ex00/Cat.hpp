/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:33:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

/**
 * @class Cat
 * @brief Derived Animal class representing a cat.
 *
 * Cat sets the inherited type field to "Cat" and overrides makeSound().
 */
class Cat : public Animal
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the inherited type field to "Cat".
	 */
	Cat(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Copies the Animal part from another Cat.
	 *
	 * @param other Cat object to copy from.
	 */
	Cat(const Cat& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Reuses Animal's assignment operator because Cat has no extra attributes.
	 *
	 * @param other Cat object to assign from.
	 * @return Reference to the current Cat object.
	 */
	Cat& operator=(const Cat& other);

	/**
	 * @brief Destructor.
	 */
	virtual ~Cat(void);

	/**
	 * @brief Print the cat sound.
	 */
	void makeSound(void) const;
};

#endif
