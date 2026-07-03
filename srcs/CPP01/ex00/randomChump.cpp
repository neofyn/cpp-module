/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:21:18 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:22:06 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a temporary stack Zombie and makes it announce itself.
 *
 * The zombie is destroyed automatically when this function ends.
 *
 * @param name The name assigned to the zombie.
 */
void randomChump(std::string name)
{
	Zombie zombie(name);

	zombie.announce();
}