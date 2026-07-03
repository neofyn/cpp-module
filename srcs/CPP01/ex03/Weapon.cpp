/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:20:42 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 18:27:44 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief Constructs a Weapon with an initial type.
 * 
 * It is read as: 
 * The Weapon constructor takes a constant reference to a std::string named 
 * type, and uses it to initialize the member variable _type.
 * 
 * _type(type) is a member initializer list.
 * 
 * It means:
 * 		_type = type;
 *
 * @param type The initial weapon type.
 */
Weapon::Weapon(const std::string &type) : _type(type)
{
}

/**
 * @brief Returns the weapon type.
 *
 * The return type is a constant reference to avoid copying the string while
 * still preventing outside code from modifying _type directly.
 *
 * @return A constant reference to the weapon type.
 */
const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

/**
 * @brief Changes the weapon type.
 *
 * HumanA and HumanB should observe this change because they do not store
 * separate copies of the Weapon object.
 *
 * @param type The new weapon type.
 */
void Weapon::setType(const std::string &type)
{
	this->_type = type;
}