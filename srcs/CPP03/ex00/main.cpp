/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 21:34:20 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/**
 * @brief Runs manual tests for CPP03 ex00.
 *
 * This test program checks:
 * - basic attack, damage, and repair behavior
 * - energy exhaustion
 * - hit point exhaustion
 * - Orthodox Canonical Form behavior
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	std::cout << "--- Basic behavior ---" << std::endl;
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");

	alpha.attack("Beta");
	beta.takeDamage(0);
	beta.beRepaired(3);

	std::cout << std::endl;
	std::cout << "--- Energy exhaustion ---" << std::endl;
	ClapTrap energyBot("EnergyBot");

	for (int i = 0; i < 11; i++)
		energyBot.attack("training dummy");

	std::cout << std::endl;

	std::cout << "--- Hit point exhaustion ---" << std::endl;
	beta.takeDamage(100);
	beta.attack("Alpha");
	beta.beRepaired(5);
	beta.takeDamage(1);

	std::cout << std::endl;
	
	std::cout << "--- Orthodox Canonical Form tests ---" << std::endl;
	ClapTrap copy(alpha);
	ClapTrap assigned("Assigned");

	assigned = alpha;
	copy.attack("copy target");
	assigned.attack("assigned target");

	return (0);
}
