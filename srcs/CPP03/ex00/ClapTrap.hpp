/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 22:35:09 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

/**
 * @class ClapTrap
 * @brief Represents a small combat robot with health, energy, and damage.
 *
 * This class is the base object for CPP03. In ex00, ClapTrap does not interact
 * directly with other ClapTrap instances. The target of attack() is only a
 * string used for printing a message.
 */
class ClapTrap
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Creates a ClapTrap with the default name "default" and the required
	 * starting values: 10 hit points, 10 energy points, and 0 attack damage.
	 */
	ClapTrap(void);

	/**
	 * @brief Name constructor.
	 *
	 * Creates a ClapTrap with a custom name and the required starting values:
	 * 10 hit points, 10 energy points, and 0 attack damage.
	 *
	 * @param name The name assigned to this ClapTrap.
	 */
	ClapTrap(const std::string &name);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new ClapTrap by copying the internal state of another ClapTrap.
	 *
	 * @param other The ClapTrap object to copy from.
	 */
	ClapTrap(const ClapTrap &other);

	/**
	 * @brief Destructor.
	 *
	 * Called automatically when a ClapTrap object is destroyed.
	 */
	~ClapTrap(void);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies the internal state of another existing ClapTrap into this object.
	 *
	 * @param other The ClapTrap object to copy from.
	 * @return A reference to the current object.
	 */
	ClapTrap &operator=(const ClapTrap &other);

	/**
	 * @brief Attacks a target and spends one energy point.
	 *
	 * The target is only a string. It does not represent another real ClapTrap
	 * object in this exercise.
	 *
	 * @param target The name of the target printed in the attack message.
	 */
	void attack(const std::string &target);

	/**
	 * @brief Reduces the ClapTrap's hit points.
	 *
	 * Hit points are clamped at 0 to avoid unsigned integer underflow.
	 *
	 * @param amount The amount of damage received.
	 */
	void takeDamage(unsigned int amount);

	/**
	 * @brief Repairs the ClapTrap and spends one energy point.
	 *
	 * The ClapTrap cannot repair itself if it has 0 hit points or 0 energy
	 * points.
	 *
	 * @param amount The amount of hit points restored.
	 */
	void beRepaired(unsigned int amount);

private:
	std::string  _name;         /**< Name of the ClapTrap. */
	unsigned int _hitPoints;    /**< Health points. Starts at 10. */
	unsigned int _energyPoints; /**< Energy used by attack and repair. */
	unsigned int _attackDamage; /**< Damage caused by attack. Starts at 0. */
};

#endif
