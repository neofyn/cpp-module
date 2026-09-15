/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:14:24 by fyudris           #+#    #+#             */
/*   Updated: 2026/09/15 19:25:41 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

/**
 * @brief Represents a beraucrat with a fixed name and a grade.
 *
 * A Bureaucrat has:
 * - a constant name
 * - a grade between 1 (highest) and 150 (lowest)
 */
class Bureaucrat
{
	private:
		const std::string 	_name;	// constant name
		int 				_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		/**
		 * @brief Exception thrown when a grade is higher than grade 1.
		 */
		class GradeTooHighException : public std::exception
		{
			public:
				/**
				 * @brief Return a description of error.
				 */
				virtual const char *what() const throw();
		};

		/**
		 * @brief Exception thrown when a grade is lower than grade 150.
		 */
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
}

/**
 * @brief Print a Bureaucrat.
 *
 * Format:
 * <name>, bureaucrat grade <grade>.
 */
std::ostream &
operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
