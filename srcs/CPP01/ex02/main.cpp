/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:47:51 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 17:56:39 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/**
 * @brief Demonstrates the relationship between a string, a pointer,
 *        and a reference.
 *
 * The program prints the memory addresses and values of:
 * - the original string variable
 * - a pointer to the string
 * - a reference to the string
 */
int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string:    " << &string << std::endl;
	std::cout << "Address held by PTR:  " << stringPTR << std::endl;
	std::cout << "Address held by REF:  " << &stringREF << std::endl;

	std::cout << "Value of string:      " << string << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value held by REF:    " << stringREF << std::endl;

	return (0);
}