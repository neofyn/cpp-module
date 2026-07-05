/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:04 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 22:35:36 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/**
 * @brief Default constructor implementation.
 *
 * Initializes a ClapTrap with the default name and ex00 default stats.
 */
ClapTrap::ClapTrap(void)
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Name constructor implementation.
 *
 * Initializes a ClapTrap with a custom name and ex00 default stats.
 *
 * @param name Name assigned to the ClapTrap.
 */
ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy constructor implementation.
 *
 * Copies all state from another ClapTrap.
 *
 * @param other ClapTrap object copied from.
 */
ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Destructor implementation.
 *
 * Prints a message so the destruction order can be observed.
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy assignment operator implementation.
 *
 * Copies all attributes from another ClapTrap, while protecting against
 * self-assignment.
 *
 * @param other ClapTrap object assigned from.
 * @return Reference to the current object.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called for "
			  << this->_name << std::endl;
	return (*this);
}

/**
 * @brief Makes the ClapTrap attack a target.
 *
 * The attack only happens if the ClapTrap has hit points and energy points.
 * Attacking spends exactly one energy point.
 *
 * @param target Name of the target.
 */
void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot attack because it has no hit points."
				  << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot attack because it has no energy points."
				  << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
}

/**
 * @brief Applies damage to the ClapTrap.
 *
 * Damage does not cost energy. Hit points are reduced but never below 0.
 *
 * @param amount Amount of damage received.
 */
void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int actualDamage;

	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is already out of hit points."
				  << std::endl;
		return;
	}
	actualDamage = amount;
	if (actualDamage > this->_hitPoints)
		actualDamage = this->_hitPoints;
	this->_hitPoints -= actualDamage;
	std::cout << "ClapTrap " << this->_name << " takes "
			  << actualDamage << " points of damage and has "
			  << this->_hitPoints << " hit points left."
			  << std::endl;
}

/**
 * @brief Repairs the ClapTrap.
 *
 * Repairing is only possible if the ClapTrap has hit points and energy points.
 * Repairing spends exactly one energy point.
 *
 * @param amount Amount of hit points restored.
 */
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot repair because it has no hit points."
				  << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot repair because it has no energy points."
				  << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself for "
			  << amount << " hit points and now has "
			  << this->_hitPoints << " hit points."
			  << std::endl;
}
