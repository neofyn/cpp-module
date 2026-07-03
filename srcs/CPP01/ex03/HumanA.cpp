/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:20:10 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 18:34:04 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

/**
 * @brief Constructs a HumanA with a name and a weapon.
 *
 * HumanA always has a weapon, so the weapon is stored as a reference.
 * Because references must be initialized immediately, _weapon is initialized
 * in the initializer list.
 *
 * @param name The human's name.
 * @param weapon The weapon used by this human.
 */
HumanA::HumanA(const std::string &name, Weapon &weapon)
	: _name(name), _weapon(weapon)
{
}

/**
 * @brief Prints an attack message using the current weapon type.
 *
 * If the weapon type changes after HumanA is created, this function will print
 * the updated type because _weapon refers to the original Weapon object.
 */
void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}