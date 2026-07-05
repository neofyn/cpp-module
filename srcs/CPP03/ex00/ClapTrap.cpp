/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:04 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 22:34:45 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/**
 * @brief Default constructor.
 *
 * Initializes a ClapTrap with the default name "default".
 * The required starting values are:
 * - 10 hit points
 * - 10 energy points
 * - 0 attack damage
 */
ClapTrap::ClapTrap(void)
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Name constructor.
 *
 * Initializes a ClapTrap with a custom name.
 * The required starting values are:
 * - 10 hit points
 * - 10 energy points
 * - 0 attack damage
 *
 * @param name The name assigned to the ClapTrap.
 */
ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy constructor.
 *
 * Creates a new ClapTrap by copying all attributes from another ClapTrap.
 *
 * @param other The ClapTrap object to copy from.
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
 * @brief Destructor.
 *
 * Called automatically when a ClapTrap object is destroyed.
 * It prints a message so construction/destruction order can be observed.
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for "
			  << this->_name << std::endl;
}

/**
 * @brief Copy assignment operator.
 *
 * Copies all attributes from another already-existing ClapTrap object into
 * the current object.
 *
 * @param other The ClapTrap object to copy from.
 * @return A reference to the current object.
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
 * @brief Attacks a target and spends one energy point.
 *
 * A ClapTrap can only attack if it has at least one hit point and one energy
 * point. The target is only a string in ex00, not another ClapTrap object.
 *
 * @param target The name of the target printed in the attack message.
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
 * @brief Reduces the ClapTrap's hit points.
 *
 * Damage is passive, so it does not cost energy. The hit points are clamped
 * at zero to avoid unsigned integer underflow.
 *
 * @param amount The amount of damage received.
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
 * @brief Repairs the ClapTrap and spends one energy point.
 *
 * A ClapTrap can only repair itself if it has at least one hit point and one
 * energy point. There is no maximum hit point limit specified in the subject,
 * so the repaired hit points are allowed to go above 10.
 *
 * @param amount The amount of hit points restored.
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
