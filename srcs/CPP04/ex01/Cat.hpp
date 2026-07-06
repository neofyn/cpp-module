/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/06 22:36:25 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/**
 * @class Cat
 * @brief Animal-derived class that owns a dynamically allocated Brain.
 *
 * Cat demonstrates polymorphism and deep copy behavior. Each Cat owns its own
 * Brain, so copying a Cat must create a new Brain instead of sharing the same
 * pointer.
 */
class Cat : public Animal
{
private:
	Brain* brain;

public:
	/**
	 * @brief Default constructor.
	 *
	 * Sets the inherited type to "Cat" and allocates a Brain.
	 */
	Cat(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Copies the Animal part and creates a deep copy of the Brain.
	 *
	 * @param other Cat object to copy from.
	 */
	Cat(const Cat& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies the Animal part and replaces this Cat's Brain with a deep copy of
	 * the other Cat's Brain.
	 *
	 * @param other Cat object to assign from.
	 * @return Reference to the current Cat object.
	 */
	Cat& operator=(const Cat& other);

	/**
	 * @brief Destructor.
	 *
	 * Deletes the owned Brain.
	 */
	virtual ~Cat(void);

	/**
	 * @brief Print the cat sound.
	 */
	void makeSound(void) const;

	/**
	 * @brief Set one idea inside the Cat's Brain.
	 *
	 * @param index Idea index, from 0 to 99.
	 * @param idea New idea text.
	 */
	void setIdea(int index, const std::string& idea);

	/**
	 * @brief Get one idea from the Cat's Brain.
	 *
	 * @param index Idea index, from 0 to 99.
	 * @return The idea stored in the Cat's Brain.
	 */
	std::string getIdea(int index) const;
};

#endif
