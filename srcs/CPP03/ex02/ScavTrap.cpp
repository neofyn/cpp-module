/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 22:37:04 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/**
 * @brief Default constructor implementation.
 *
 * First calls the ClapTrap constructor, then changes the inherited attributes
 * to ScavTrap's required stats.
 */
ScavTrap::ScavTrap(void)
	: ClapTrap("default_scav")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Name constructor implementation.
 *
 * First calls the ClapTrap name constructor. After the base class is
 * constructed, the inherited attributes are updated to ScavTrap's stats.
 *
 * @param name Name assigned to the ScavTrap.
 */
ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap name constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy constructor implementation.
 *
 * Calls the ClapTrap copy constructor to copy the inherited part of the
 * object. ScavTrap has no additional attributes to copy.
 *
 * @param other ScavTrap object copied from.
 */
ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Destructor implementation.
 *
 * Prints a ScavTrap-specific message. After this destructor finishes,
 * ClapTrap's destructor is called automatically.
 */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy assignment operator implementation.
 *
 * Reuses ClapTrap::operator= because all ScavTrap state is inherited from
 * ClapTrap. This avoids duplicated copy logic.
 *
 * @param other ScavTrap object assigned from.
 * @return Reference to the current object.
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called for "
			  << this->_name << std::endl;
	return (*this);
}

/**
 * @brief Makes the ScavTrap attack a target.
 *
 * A ScavTrap can only attack if it has at least one hit point and one energy
 * point. Attacking spends exactly one energy point.
 *
 * This function intentionally prints a different message from ClapTrap's
 * attack() function, as required by the subject.
 *
 * @param target Name of the target.
 */
void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " cannot attack because it has no hit points."
				  << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " cannot attack because it has no energy points."
				  << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks "
			  << target << ", causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
}

/**
 * @brief Activates Gate keeper mode.
 *
 * This is ScavTrap's special ability. It does not cost energy because the
 * subject only says it should display a message.
 */
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name
			  << " is now in Gate keeper mode." << std::endl;
}
