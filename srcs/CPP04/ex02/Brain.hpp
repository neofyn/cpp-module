/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:40:14 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

/**
 * @class Brain
 * @brief Stores the ideas owned by a Dog or Cat.
 *
 * Brain is dynamically allocated by Dog and Cat in ex01. Because Dog and Cat
 * own Brain through a pointer, Brain must be safely copied to support deep
 * copy behavior.
 */
class Brain
{
private:
	std::string ideas[100];

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes all 100 ideas with a simple default string.
	 */
	Brain(void);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new Brain by copying every idea from another Brain.
	 *
	 * @param other Brain object to copy from.
	 */
	Brain(const Brain& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies all 100 ideas from another Brain into this Brain.
	 *
	 * @param other Brain object to assign from.
	 * @return Reference to the current Brain object.
	 */
	Brain& operator=(const Brain& other);

	/**
	 * @brief Destructor.
	 */
	~Brain(void);

	/**
	 * @brief Set one idea at a specific index.
	 *
	 * This function is useful for testing deep copies. If the index is outside
	 * the valid range, nothing is changed.
	 *
	 * @param index Index of the idea, from 0 to 99.
	 * @param idea New idea text.
	 */
	void setIdea(int index, const std::string& idea);

	/**
	 * @brief Get one idea at a specific index.
	 *
	 * If the index is outside the valid range, an empty string is returned.
	 *
	 * @param index Index of the idea, from 0 to 99.
	 * @return The idea stored at the requested index.
	 */
	std::string getIdea(int index) const;
};

#endif
