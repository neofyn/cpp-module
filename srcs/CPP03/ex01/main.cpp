/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:14:03 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/**
 * @brief Runs manual tests for CPP03 ex01.
 *
 * This program tests:
 * - normal ClapTrap behavior
 * - ScavTrap construction/destruction chaining
 * - ScavTrap-specific attack()
 * - inherited takeDamage()
 * - inherited beRepaired()
 * - ScavTrap's guardGate()
 * - Orthodox Canonical Form behavior
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	std::cout << "--- ClapTrap basic test ---" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("target dummy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << std::endl;
	std::cout << "--- ScavTrap construction and behavior ---" << std::endl;
	ScavTrap scav("Serena");
	scav.attack("bandit");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << std::endl;
	std::cout << "--- ScavTrap energy exhaustion ---" << std::endl;
	ScavTrap battery("Battery");

	for (int i = 0; i < 51; i++)
		battery.attack("training dummy");

	std::cout << std::endl;
	std::cout << "--- ScavTrap hit point exhaustion ---" << std::endl;
	ScavTrap fallen("Fallen");
	fallen.takeDamage(150);
	fallen.attack("enemy");
	fallen.beRepaired(20);
	fallen.guardGate();

	std::cout << std::endl;
	std::cout << "--- Orthodox Canonical Form tests ---" << std::endl;
	ScavTrap copy(scav);
	ScavTrap assigned("Assigned");

	assigned = scav;
	copy.attack("copy target");
	assigned.attack("assigned target");

	std::cout << std::endl;
	std::cout << "--- End of main: destructors will now run ---" << std::endl;

	return (0);
}
