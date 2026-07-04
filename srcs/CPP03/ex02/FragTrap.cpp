/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:21:57 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/**
 * @brief Default constructor implementation.
 *
 * First constructs the ClapTrap base part, then updates the inherited
 * attributes to FragTrap's required default stats.
 */
FragTrap::FragTrap(void)
	: ClapTrap("default_frag")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Name constructor implementation.
 *
 * First calls the ClapTrap name constructor. After the ClapTrap base part
 * exists, the inherited attributes are updated to FragTrap's stats.
 *
 * @param name Name assigned to the FragTrap.
 */
FragTrap::FragTrap(std::string const &name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap name constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy constructor implementation.
 *
 * Calls the ClapTrap copy constructor to copy the inherited base part.
 * FragTrap has no additional attributes to copy.
 *
 * @param other FragTrap object copied from.
 */
FragTrap::FragTrap(FragTrap const &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Destructor implementation.
 *
 * Prints a FragTrap-specific message. After this destructor finishes,
 * ClapTrap's destructor is called automatically.
 */
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy assignment operator implementation.
 *
 * Reuses ClapTrap::operator= because all FragTrap state is inherited from
 * ClapTrap.
 *
 * @param other FragTrap object assigned from.
 * @return Reference to the current object.
 */
FragTrap &FragTrap::operator=(FragTrap const &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called for "
			  << this->_name << std::endl;
	return (*this);
}

/**
 * @brief Prints FragTrap's positive high-five request.
 *
 * This function does not cost energy because the subject only says it should
 * display a positive high-five request on the standard output.
 */
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name
			  << " requests a positive high five!" << std::endl;
}
