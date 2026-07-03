/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:20:33 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 18:39:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/**
 * @brief Tests HumanA and HumanB weapon behavior.
 *
 * HumanA receives a weapon in the constructor.
 * HumanB receives a weapon later through setWeapon().
 */
int main(void)
{
	{
		Weapon club("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();

		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();

		club.setType("some other type of club");
		jim.attack();
	}
	
	return (0);
}