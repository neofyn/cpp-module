/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:26:10 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:45:37 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Tests zombieHorde().
 *
 * Creates a horde, announces every zombie, then destroys the full array with
 * delete[].
 */
int main(void)
{
	Zombie	*horde;
	int		hordeSize;
	int		i;

	hordeSize = 5;
	horde = zombieHorde(hordeSize, "HordeZombie");
	if (horde == 0)
		return (1);
	i = 0;
	while (i < hordeSize)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}