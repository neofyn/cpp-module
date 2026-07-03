/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:11:31 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 19:44:54 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief Constructs a Harl object.
 *
 * This class has no attributes, so the constructor does not need to initialize
 * anything.
 */
Harl::Harl(void)
{
}

/**
 * @brief Destroys a Harl object.
 *
 * This class does not allocate memory, so the destructor does not need to free
 * anything.
 */
Harl::~Harl(void)
{
}

/**
 * @brief Prints Harl's DEBUG-level complaint.
 */
void Harl::debug(void)
{
	std::cout
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!"
		<< std::endl;
}

/**
 * @brief Prints Harl's INFO-level complaint.
 */
void Harl::info(void)
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!"
		<< std::endl;
}

/**
 * @brief Prints Harl's WARNING-level complaint.
 */
void Harl::warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years, whereas you started working "
		<< "here just last month."
		<< std::endl;
}

/**
 * @brief Prints Harl's ERROR-level complaint.
 */
void Harl::error(void)
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

/**
 * @brief Calls the complaint function matching the given level.
 *
 * This function uses an array of strings and an array of pointers to member
 * functions. It avoids a long if/else if chain.
 *
 * @param level The complaint level to execute.
 */
void Harl::complain(std::string level)
{
	std::string			levels[4];
	ComplaintFunction	functions[4];
	int					i;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
		i++;
	}
	std::cout << "Invalid complaint level." << std::endl;
}