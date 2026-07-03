/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:50:40 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:22:56 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a Zombie on the heap.
 *
 * The returned zombie survives after this function ends.
 * The caller must later destroy it with delete.
 *
 * @param name The name assigned to the zombie.
 *
 * @return A pointer to the created zombie.
 */
Zombie *newZombie(std::string name)
{
	Zombie *zombie;

	zombie = new Zombie(name);
	return (zombie);
}