/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:21:43 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

/**
 * @class FragTrap
 * @brief Derived robot class with stronger stats and a high-five ability.
 *
 * FragTrap publicly inherits from ClapTrap. It reuses ClapTrap's inherited
 * attributes and member functions, but changes the initial stats to:
 * - 100 hit points
 * - 100 energy points
 * - 30 attack damage
 *
 * FragTrap does not redeclare name, hit points, energy points, or attack
 * damage. Those attributes are inherited from ClapTrap.
 */
class FragTrap : public ClapTrap
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Creates a FragTrap with a default name and FragTrap stats.
	 */
	FragTrap(void);

	/**
	 * @brief Name constructor.
	 *
	 * Creates a FragTrap with the given name and FragTrap stats.
	 *
	 * @param name Name assigned to the FragTrap.
	 */
	FragTrap(std::string const &name);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new FragTrap by copying another FragTrap.
	 *
	 * @param other FragTrap object used as the copy source.
	 */
	FragTrap(FragTrap const &other);

	/**
	 * @brief Destructor.
	 *
	 * Prints a FragTrap-specific destruction message.
	 */
	~FragTrap(void);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Reuses ClapTrap's assignment logic because FragTrap has no extra
	 * attributes of its own.
	 *
	 * @param other FragTrap object used as the assignment source.
	 * @return Reference to the current object.
	 */
	FragTrap &operator=(FragTrap const &other);

	/**
	 * @brief Prints a positive high-five request.
	 *
	 * This is FragTrap's special ability required by ex02.
	 */
	void highFivesGuys(void);
};

#endif
