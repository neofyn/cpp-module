/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:46:51 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/27 15:49:57 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Construct a Zombie with a name
 * 
 * @param name The name assigned to the zombie.
 */
Zombie::Zombie(std::string name)
{
	this->_name = name;	
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}