/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/06 22:36:27 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/**
 * @class Dog
 * @brief Animal-derived class that owns a dynamically allocated Brain.
 *
 * Dog demonstrates polymorphism and deep copy behavior. Each Dog owns its own
 * Brain, so copying a Dog must create a new Brain instead of sharing the same
 * pointer.
 */
class Dog : public Animal
{
private:
	Brain* brain;

public:
	/**
	 * @brief Default constructor.
	 *
	 * Sets the inherited type to "Dog" and allocates a Brain.
	 */
	Dog(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Copies the Animal part and creates a deep copy of the Brain.
	 *
	 * @param other Dog object to copy from.
	 */
	Dog(const Dog& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies the Animal part and replaces this Dog's Brain with a deep copy of
	 * the other Dog's Brain.
	 *
	 * @param other Dog object to assign from.
	 * @return Reference to the current Dog object.
	 */
	Dog& operator=(const Dog& other);

	/**
	 * @brief Destructor.
	 *
	 * Deletes the owned Brain.
	 */
	virtual ~Dog(void);

	/**
	 * @brief Print the dog sound.
	 */
	void makeSound(void) const;

	/**
	 * @brief Set one idea inside the Dog's Brain.
	 *
	 * @param index Idea index, from 0 to 99.
	 * @param idea New idea text.
	 */
	void setIdea(int index, const std::string& idea);

	/**
	 * @brief Get one idea from the Dog's Brain.
	 *
	 * @param index Idea index, from 0 to 99.
	 * @return The idea stored in the Dog's Brain.
	 */
	std::string getIdea(int index) const;
};

#endif
