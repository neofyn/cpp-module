/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:26:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:43:49 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Constructs a Zombie with a default name.
 *
 * This constructor is required because zombieHorde() creates an array with
 * new Zombie[N]. When an array of objects is created this way, C++ first calls
 * the default constructor for each object.
 */
Zombie::Zombie(void) : _name("Unnamed")
{
}

/**
 * @brief Destroys a Zombie object.
 *
 * The destructor prints the zombie name so we can verify that delete[] properly
 * destroys every zombie in the horde.
 */
Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

/**
 * @brief Sets the zombie's name.
 *
 * This is used after the horde array has been allocated.
 *
 * @param name The name assigned to the zombie.
 */
void Zombie::setName(const std::string &name)
{
	this->_name = name;
}

/**
 * @brief Prints the zombie announcement.
 *
 * The function is const because it only reads the zombie name and does not
 * modify the object.
 */
void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}