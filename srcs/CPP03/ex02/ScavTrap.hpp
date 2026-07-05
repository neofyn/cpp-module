/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 22:37:30 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief Derived robot class that specializes ClapTrap behavior.
 *
 * ScavTrap publicly inherits from ClapTrap. It reuses the inherited
 * attributes and functions, but changes the initial stats and provides a
 * different attack() message.
 *
 * ScavTrap does not redeclare name, hit points, energy points, or attack
 * damage. Those attributes are inherited from ClapTrap.
 */
class ScavTrap : public ClapTrap
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Creates a ScavTrap with a default name and ScavTrap stats:
	 * 100 hit points, 50 energy points, and 20 attack damage.
	 */
	ScavTrap(void);

	/**
	 * @brief Name constructor.
	 *
	 * Creates a ScavTrap with the given name and ScavTrap stats:
	 * 100 hit points, 50 energy points, and 20 attack damage.
	 *
	 * @param name Name assigned to the ScavTrap.
	 */
	ScavTrap(const std::string &name);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new ScavTrap by copying another ScavTrap.
	 *
	 * @param other ScavTrap object used as the copy source.
	 */
	ScavTrap(const ScavTrap &other);

	/**
	 * @brief Destructor.
	 *
	 * Prints a ScavTrap-specific destruction message.
	 */
	~ScavTrap(void);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Reuses ClapTrap's assignment logic because ScavTrap has no extra
	 * attributes of its own.
	 *
	 * @param other ScavTrap object used as the assignment source.
	 * @return Reference to the current object.
	 */
	ScavTrap &operator=(const ScavTrap &other);

	/**
	 * @brief ScavTrap-specific attack.
	 *
	 * Works like ClapTrap::attack(), but prints a different message and uses
	 * ScavTrap's attack damage value.
	 *
	 * @param target Name of the target printed in the message.
	 */
	void attack(const std::string &target);

	/**
	 * @brief Activates Gate keeper mode.
	 *
	 * Prints a message showing that this ScavTrap is now guarding the gate.
	 */
	void guardGate(void);
};

#endif
