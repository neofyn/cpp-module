/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 10:51:04 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/25 11:11:16 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

/**
 * @class PhoneBook
 * @brief Stores and manages up to 8 Contact objects.
 *
 * The PhoneBook class owns an array of 8 Contact objects.
 *
 * Dynamic allocation is forbidden in this exercise, so we use:
 *
 * @code
 * Contact _contacts[8];
 * @endcode
 *
 * instead of:
 *
 * @code
 * new Contact[8];
 * @endcode
 *
 * The phonebook keeps track of:
 * - how many contacts are currently stored
 * - where the next contact should be inserted
 *
 * When the 9th contact is added, the oldest contact is replaced.
 */
class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;

private:
	Contact	_contacts[8];
	int		_contactCount;
	int		_nextIndex;

	bool		_readNonEmptyField(const std::string& prompt,
					std::string& output) const;
	std::string	_formatColumn(const std::string& value) const;
	bool		_isValidIndexInput(const std::string& input,
					int& index) const;
	void		_printContactRow(int index) const;
	void		_printContactDetails(int index) const;
};

#endif