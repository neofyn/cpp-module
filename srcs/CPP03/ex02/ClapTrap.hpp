/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 22:36:00 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

/**
 * @class ClapTrap
 * @brief Base combat robot class for CPP03.
 *
 * ClapTrap stores the common state shared by all trap types:
 * name, hit points, energy points, and attack damage.
 *
 * In ex01, these attributes are protected instead of private so derived
 * classes such as ScavTrap can reuse and modify them without redeclaring them.
 */
class ClapTrap
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Creates a ClapTrap named "default" with 10 hit points,
	 * 10 energy points, and 0 attack damage.
	 */
	ClapTrap(void);

	/**
	 * @brief Name constructor.
	 *
	 * Creates a ClapTrap with the given name and the default ClapTrap stats.
	 *
	 * @param name Name assigned to the ClapTrap.
	 */
	ClapTrap(const std::string &name);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new ClapTrap by copying another ClapTrap.
	 *
	 * @param other ClapTrap object used as the copy source.
	 */
	ClapTrap(const ClapTrap &other);

	/**
	 * @brief Destructor.
	 *
	 * Prints a message when the ClapTrap object is destroyed.
	 */
	~ClapTrap(void);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Copies all ClapTrap attributes from another existing ClapTrap.
	 *
	 * @param other ClapTrap object used as the assignment source.
	 * @return Reference to the current object.
	 */
	ClapTrap &operator=(const ClapTrap &other);

	/**
	 * @brief Attacks a target and spends one energy point.
	 *
	 * @param target Name of the target printed in the message.
	 */
	void attack(const std::string &target);

	/**
	 * @brief Reduces hit points by the given amount.
	 *
	 * Hit points are clamped at 0 to avoid unsigned integer underflow.
	 *
	 * @param amount Amount of damage received.
	 */
	void takeDamage(unsigned int amount);

	/**
	 * @brief Repairs the ClapTrap and spends one energy point.
	 *
	 * @param amount Amount of hit points restored.
	 */
	void beRepaired(unsigned int amount);

protected:
	std::string  _name;         /**< Name of the robot. */
	unsigned int _hitPoints;    /**< Health points. */
	unsigned int _energyPoints; /**< Energy used by attack and repair. */
	unsigned int _attackDamage; /**< Damage caused by attack. */
};

#endif
