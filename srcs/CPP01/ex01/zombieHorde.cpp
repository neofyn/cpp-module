/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:21:01 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:43:29 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Allocates and initializes a horde of Zombies.
 *
 * The horde is allocated with a single call to new Zombie[N].
 * Each zombie is then initialized with the same name.
 *
 * Because this function uses new[], the caller must later use delete[].
 *
 * @param N The number of zombies to allocate.
 * @param name The name assigned to every zombie in the horde.
 *
 * @return A pointer to the first zombie in the horde, or 0 if N is invalid.
 */
Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*zombies;
	int		i;

	if (N <= 0)
		return (0);
	zombies = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return (zombies);
}