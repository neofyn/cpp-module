/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 09:03:22 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/14 15:00:37 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/**
 * @file megaphone.cpp
 * @brief CPP00 ex00: convert command-line arguments to uppercase.
 *
 * This program reproduces the behavior required by the CPP00 ex00 subject:
 * - If the program receives arguments, it prints all arguments in uppercase.
 * - If the program receives no argument, it prints:
 *   "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
 
 * @note Why static_cast<unsigned char> is used:
 *
 * std::toupper expects an int value that is either EOF or representable as
 * an unsigned char. A plain char may be signed depending on the system.
 * If a signed char contains a negative value and is passed directly to
 * std::toupper, the behavior can be undefined.
 *
 * Therefore, this program first converts the character to unsigned char:
 *
 * @code
 * static_cast<unsigned char>(argv[i][j])
 * @endcode
 *
 * Then std::toupper returns an int. Since we want to print the uppercase
 * character, not its numeric ASCII value, the result is cast back to char:
 *
 * @code
 * static_cast<char>(std::toupper(...))
 * @endcode
 */
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			std::cout << static_cast<char>(
				std::toupper(static_cast<unsigned char>(argv[i][j]))
			);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
