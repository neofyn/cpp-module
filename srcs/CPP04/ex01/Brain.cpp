/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:40:22 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**
 * @brief Default constructor.
 */
Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "empty idea";
}

/**
 * @brief Copy constructor.
 */
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator.
 */
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

/**
 * @brief Destructor.
 */
Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

/**
 * @brief Set one idea at a specific index.
 */
void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = idea;
}

/**
 * @brief Get one idea at a specific index.
 */
std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->ideas[index]);
}
