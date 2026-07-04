/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:20:21 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/**
 * @brief Runs manual tests for CPP03 ex02.
 *
 * This program tests:
 * - ClapTrap base behavior
 * - ScavTrap behavior from ex01
 * - FragTrap construction/destruction chaining
 * - FragTrap inherited attack(), takeDamage(), and beRepaired()
 * - FragTrap highFivesGuys()
 * - Orthodox Canonical Form behavior
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	std::cout << "--- ClapTrap test ---" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("target dummy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << std::endl;
	std::cout << "--- ScavTrap test ---" << std::endl;
	ScavTrap scav("Serena");
	scav.attack("bandit");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << std::endl;
	std::cout << "--- FragTrap test ---" << std::endl;
	FragTrap frag("Frank");
	frag.attack("training dummy");
	frag.takeDamage(40);
	frag.beRepaired(15);
	frag.highFivesGuys();

	std::cout << std::endl;
	std::cout << "--- FragTrap hit point exhaustion ---" << std::endl;
	FragTrap fallen("FallenFrag");
	fallen.takeDamage(150);
	fallen.attack("enemy");
	fallen.beRepaired(20);
	fallen.highFivesGuys();

	std::cout << std::endl;
	std::cout << "--- Orthodox Canonical Form tests ---" << std::endl;
	FragTrap copy(frag);
	FragTrap assigned("AssignedFrag");

	assigned = frag;
	copy.attack("copy target");
	assigned.highFivesGuys();

	std::cout << std::endl;
	std::cout << "--- End of main: destructors will now run ---" << std::endl;

	return (0);
}
