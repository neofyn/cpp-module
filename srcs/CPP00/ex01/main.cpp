/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:49:58 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/25 11:12:28 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

/**
 * @brief Entry point of the phonebook program.
 *
 * The program creates one PhoneBook object and repeatedly asks the user for a
 * command.
 *
 * Valid commands:
 * - ADD
 * - SEARCH
 * - EXIT
 *
 * Any other command is ignored.
 *
 * @return 0 when the program exits successfully.
 */
int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}