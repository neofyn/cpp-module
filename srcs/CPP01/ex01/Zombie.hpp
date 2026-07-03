/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:26:26 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:36:14 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(void);
	~Zombie(void);

	void setName(const std::string &name);
	void announce(void) const;
};

Zombie *zombieHorde(int N, std::string name);

#endif