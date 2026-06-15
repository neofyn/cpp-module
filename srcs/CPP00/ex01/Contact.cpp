/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:02:41 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/15 12:54:02 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * @file Contact.cpp 
 * 
 * @brief Setter functions for the Contact class.
 * 
 * @note Why const std::string& is used:
 * 
 * 1. `&` means reference. 
 * The & here does not mean “address of” like in some C contexts. A reference 
 * is like an alias, or another name, for an existing variable. So the function
 * would receive the original string directly, instead of a copy.
 * 
 * 
 * 2. `const` means “do not modify it”. If you only write: std::string& 
 * firstName, then the function could (accidentaly) change the original 
 * argument, such as:
 * @code
 * void Contact::setFirstName(std::string& firstName)
 * {
 * 	firstName = "Changed!"; // unintended modification
 * }
 * @endcode
 */
void	Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

/**
 * @brief Getter functions for the Contact class
 */
const std::string&	Contact::getFirstName(void) const
{
	return (_firstName);
}

const std::string&	Contact::getLastName(void) const
{
	return (_lastName);
}

const std::string&	Contact::getNickname(void) const
{
	return (_nickname);
}

const std::string&	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

const std::string&	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

