/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:02:53 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/25 11:09:04 by fyudris          ###   ########.fr       */
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

	void				setFirstName(const std::string& firstName);
	void				setLastName(const std::string& lastName);
	void				setNickname(const std::string& nickname);
	void				setPhoneNumber(const std::string& phoneNumber);
	void				setDarkestSecret(const std::string& darkestSecret);

	const std::string&	getFirstName(void) const;
	const std::string&	getLastName(void) const;
	const std::string&	getNickname(void) const;
	const std::string&	getPhoneNumber(void) const;
	const std::string&	getDarkestSecret(void) const;

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif