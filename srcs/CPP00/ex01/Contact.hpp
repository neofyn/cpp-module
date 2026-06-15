/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 15:02:53 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/15 11:56:09 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{	
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		
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
};



#endif