/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:49:58 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/15 11:53:05 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

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
			break;
	}
	return (0);
}