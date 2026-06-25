/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:05:02 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/25 13:08:10 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

/**
 * @brief Default constructor for PhoneBook.
 *
 * This function is called automatically when a PhoneBook object is created.
 *
 * The initializer list sets:
 * - _contactCount to 0, because the phonebook starts empty
 * - _nextIndex to 0, because the first contact should be stored at index 0
 *
 * The array _contacts already contains 8 Contact objects. No dynamic allocation
 * is used.
 */
PhoneBook::PhoneBook(void) : _contactCount(0), _nextIndex(0)
{
}

/**
 * @brief Destructor for PhoneBook.
 *
 * Since this class does not allocate memory manually, there is nothing special
 * to clean up.
 */
PhoneBook::~PhoneBook(void)
{
}

/**
 * @brief Read one non-empty field from standard input.
 *
 * @param prompt The message shown to the user before reading input.
 * @param output The string where the valid input will be stored.
 *
 * @return true if input was successfully read.
 * @return false if input ends, for example with Ctrl-D.
 *
 * This function is used by PhoneBook::add().
 *
 * The subject says that a saved contact cannot have empty fields, so this
 * helper function keeps asking until the user enters something non-empty.
 */
bool	PhoneBook::_readNonEmptyField(const std::string& prompt,
			std::string& output) const
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, output))
			return (false);
		if (!output.empty())
			return (true);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

/**
 * @brief Format a string so it fits inside a SEARCH table column.
 *
 * @param value The original string.
 *
 * @return The formatted string.
 *
 * The subject requires each SEARCH column to be 10 characters wide.
 *
 * If a string is longer than 10 characters, it must be truncated and the last
 * displayable character must become a dot.
 *
 * Example:
 * "Alexanderson" becomes "Alexander."
 */
std::string	PhoneBook::_formatColumn(const std::string& value) const
{
	if (value.length() > 10)
		return (value.substr(0, 9) + ".");
	return (value);
}

/**
 * @brief Check whether the user's SEARCH index input is valid.
 *
 * @param input The raw string entered by the user.
 * @param index Output variable where the parsed valid index will be stored.
 *
 * @return true if the input is a valid saved contact index.
 * @return false otherwise.
 *
 * This function rejects:
 * - empty input
 * - non-numeric input
 * - input with extra characters, such as "1abc"
 * - negative indexes
 * - indexes outside the saved contact range
 *
 * std::istringstream is used here to parse the string safely instead of atoi.
 */
bool	PhoneBook::_isValidIndexInput(const std::string& input,
			int& index) const
{
	std::istringstream	stream(input);
	int					parsedIndex;
	char				extra;

	if (!(stream >> parsedIndex))
		return (false);
	if (stream >> extra)
		return (false);
	if (parsedIndex < 0 || parsedIndex >= _contactCount)
		return (false);
	index = parsedIndex;
	return (true);
}

/**
 * @brief Print one contact row in the SEARCH table.
 *
 * @param index The index of the contact to print.
 *
 * This function prints only the short table information:
 * - index
 * - first name
 * - last name
 * - nickname
 *
 * Each column is printed with std::setw(10), as required by the subject.
 */
void	PhoneBook::_printContactRow(int index) const
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10)
		<< _formatColumn(_contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10)
		<< _formatColumn(_contacts[index].getLastName()) << "|";
	std::cout << std::setw(10)
		<< _formatColumn(_contacts[index].getNickname()) << std::endl;
}

/**
 * @brief Print all information of one selected contact.
 *
 * @param index The index of the contact to display.
 *
 * This is called after the user enters a valid index in SEARCH mode.
 */
void	PhoneBook::_printContactDetails(int index) const
{
	std::cout << "First name: "
		<< _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: "
		<< _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: "
		<< _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: "
		<< _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: "
		<< _contacts[index].getDarkestSecret() << std::endl;
}

/**
 * @brief Add a new contact to the phonebook.
 *
 * The function asks the user for all five required fields:
 * - first name
 * - last name
 * - nickname
 * - phone number
 * - darkest secret
 *
 * Empty fields are rejected.
 *
 * The new contact is stored at _contacts[_nextIndex].
 *
 * After saving, _nextIndex moves to the next slot. When it reaches 8, it wraps
 * back to 0. This creates the required behavior: adding a 9th contact replaces
 * the oldest contact.
 */
void	PhoneBook::add(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!_readNonEmptyField("First name: ", firstName))
		return ;
	if (!_readNonEmptyField("Last name: ", lastName))
		return ;
	if (!_readNonEmptyField("Nickname: ", nickname))
		return ;
	if (!_readNonEmptyField("Phone number: ", phoneNumber))
		return ;
	if (!_readNonEmptyField("Darkest secret: ", darkestSecret))
		return ;
	_contacts[_nextIndex].setFirstName(firstName);
	_contacts[_nextIndex].setLastName(lastName);
	_contacts[_nextIndex].setNickname(nickname);
	_contacts[_nextIndex].setPhoneNumber(phoneNumber);
	_contacts[_nextIndex].setDarkestSecret(darkestSecret);
	std::cout << "Contact saved at index " << _nextIndex << "." << std::endl;
	_nextIndex++;
	if (_nextIndex == 8)
		_nextIndex = 0;
	if (_contactCount < 8)
		_contactCount++;
}

/**
 * @brief Search and display contacts.
 *
 * If the phonebook is empty, the function prints a message and returns.
 *
 * Otherwise, it prints a table with:
 * - index
 * - first name
 * - last name
 * - nickname
 *
 * Then it asks the user for an index.
 *
 * If the index is valid, the full contact information is displayed.
 * If the index is invalid, an error message is printed.
 */
void	PhoneBook::search(void) const
{
	std::string	input;
	int			index;
	int			i;

	if (_contactCount == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	i = 0;
	while (i < _contactCount)
	{
		_printContactRow(i);
		i++;
	}
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, input))
		return ;
	if (!_isValidIndexInput(input, index))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	_printContactDetails(index);
}