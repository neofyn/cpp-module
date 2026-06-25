/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:02:53 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/25 11:01:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

/**
 * @class Contact
 * @brief Represents one contact stored inside the phonebook.
 *
 * A Contact object stores the five fields required by the subject:
 * first name, last name, nickname, phone number, and darkest secret.
 *
 * All attributes are private to protect the internal state of the object.
 * Outside code must use setters and getters to interact with the contact.
 *
 * This is an example of encapsulation:
 * - data is hidden in the private section
 * - controlled access is given through public member functions
 */
class Contact
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Called automatically when a Contact object is created.
	 * In this exercise, the constructor does not need to manually initialize
	 * the std::string attributes because std::string automatically starts 
	 * empty.
	 */
	Contact(void);

	/**
	 * @brief Destructor.
	 *
	 * Called automatically when a Contact object is destroyed.
	 * Since this class does not use dynamic allocation, the destructor has
	 * nothing special to clean up.
	 */
	~Contact(void);

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	/**
	 * @brief Set the contact's first name.
	 * @param firstName The first name to store.
	 *
	 * The parameter is passed as const std::string& to avoid an unnecessary 
	 * copy while also preventing the function from modifying the input 
	 * parameter.
	 */
	void				setFirstName(const std::string& firstName);

	/**
	 * @brief Set the contact's last name.
	 * @param lastName The last name to store.
	 */
	void				setLastName(const std::string& lastName);

	/**
	 * @brief Set the contact's nickname.
	 * @param nickname The nickname to store.
	 */
	void				setNickname(const std::string& nickname);

	/**
	 * @brief Set the contact's phone number.
	 * @param phoneNumber The phone number to store.
	 */
	void				setPhoneNumber(const std::string& phoneNumber);

	/**
	 * @brief Set the contact's darkest secret.
	 * @param darkestSecret The darkest secret to store.
	 */
	void				setDarkestSecret(const std::string& darkestSecret);

	/**
	 * @brief Get the contact's first name.
	 * @return A const reference to the first name.
	 *
	 * Returning const std::string& avoids copying the string and prevents 
	 * outside code from modifying the private attribute directly.
	 *
	 * The final const means this getter does not modify the Contact object.
	 */
	const std::string&	getFirstName(void) const;

	/**
	 * @brief Get the contact's last name.
	 * @return A const reference to the last name.
	 */
	const std::string&	getLastName(void) const;

	/**
	 * @brief Get the contact's nickname.
	 * @return A const reference to the nickname.
	 */
	const std::string&	getNickname(void) const;

	/**
	 * @brief Get the contact's phone number.
	 * @return A const reference to the phone number.
	 */
	const std::string&	getPhoneNumber(void) const;

	/**
	 * @brief Get the contact's darkest secret.
	 * @return A const reference to the darkest secret.
	 */
	const std::string&	getDarkestSecret(void) const;
};

#endif