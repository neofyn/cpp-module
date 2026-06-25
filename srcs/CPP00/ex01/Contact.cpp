/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:02:41 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/25 11:14:24 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * @brief Default constructor for Contact.
 *
 * This function is called automatically when a Contact object is created.
 *
 * In this exercise, the constructor body is empty because all Contact attributes
 * are std::string objects, and std::string automatically initializes itself as
 * an empty string.
 *
 * Example:
 * @code
 * Contact contact;
 * @endcode
 *
 * The line above automatically calls Contact::Contact().
 */
Contact::Contact(void)
{
}

/**
 * @brief Destructor for Contact.
 *
 * This function is called automatically when a Contact object is destroyed.
 *
 * Since this class does not allocate memory manually with new, there is nothing
 * special to clean up here.
 */
Contact::~Contact(void)
{
}

/**
 * @brief Store the first name inside the Contact object.
 *
 * @param firstName The first name entered by the user.
 *
 * The parameter is passed as const std::string&.
 *
 * The ampersand means the string is passed by reference, so C++ avoids making
 * an unnecessary copy of the string.
 *
 * The const means this function promises not to modify the input parameter.
 *
 * Inside the function, we copy the value into the private member variable
 * _firstName.
 */
void	Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

/**
 * @brief Store the last name inside the Contact object.
 *
 * @param lastName The last name entered by the user.
 */
void	Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

/**
 * @brief Store the nickname inside the Contact object.
 *
 * @param nickname The nickname entered by the user.
 */
void	Contact::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

/**
 * @brief Store the phone number inside the Contact object.
 *
 * @param phoneNumber The phone number entered by the user.
 */
void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

/**
 * @brief Store the darkest secret inside the Contact object.
 *
 * @param darkestSecret The darkest secret entered by the user.
 */
void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

/**
 * @brief Get the contact's first name.
 *
 * @return A const reference to the stored first name.
 *
 * The return type is const std::string&.
 *
 * The ampersand means we return a reference, so C++ avoids copying the string.
 *
 * The const before std::string means the caller can read the returned string,
 * but cannot modify it.
 *
 * The const at the end of the function means this getter promises not to modify
 * the Contact object.
 */
const std::string&	Contact::getFirstName(void) const
{
	return (_firstName);
}

/**
 * @brief Get the contact's last name.
 *
 * @return A const reference to the stored last name.
 */
const std::string&	Contact::getLastName(void) const
{
	return (_lastName);
}

/**
 * @brief Get the contact's nickname.
 *
 * @return A const reference to the stored nickname.
 */
const std::string&	Contact::getNickname(void) const
{
	return (_nickname);
}

/**
 * @brief Get the contact's phone number.
 *
 * @return A const reference to the stored phone number.
 */
const std::string&	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

/**
 * @brief Get the contact's darkest secret.
 *
 * @return A const reference to the stored darkest secret.
 */
const std::string&	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}