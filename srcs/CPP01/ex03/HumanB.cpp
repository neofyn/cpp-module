/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 18:35:58 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

/**
 * @brief Constructs a HumanB with a name but no weapon.
 *
 * HumanB may be unarmed, so _weapon is stored as a pointer and initialized
 * to 0.
 *
 * @param name The human's name.
 */
HumanB::HumanB(const std::string &name) : _name(name), _weapon(0)
{
}

/**
 * @brief Gives HumanB a weapon.
 *
 * The address of the provided weapon is stored. No copy of the weapon is made.
 *
 * @param weapon The weapon that HumanB will use.
 */
void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

/**
 * @brief Prints an attack message using the current weapon type.
 *
 * If HumanB has no weapon, this function prints a simple safety message instead
 * of dereferencing a null pointer.
 */
void HumanB::attack(void) const
{
	if (this->_weapon == 0)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their "
		<< this->_weapon->getType() << std::endl;
}