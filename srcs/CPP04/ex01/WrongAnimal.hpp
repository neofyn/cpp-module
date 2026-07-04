/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:58:21 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/04 19:34:01 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

/**
 * @class WrongAnimal
 * @brief Base class intentionally written without virtual makeSound().
 *
 * This class demonstrates static binding. When makeSound() is called through
 * a WrongAnimal pointer, C++ uses WrongAnimal::makeSound(), even if the real
 * object is a WrongCat.
 */
class WrongAnimal
{
protected:
	std::string type;

public:
	/**
	 * @brief Default constructor.
	 */
	WrongAnimal(void);

	/**
	 * @brief Copy constructor.
	 *
	 * @param other WrongAnimal object to copy from.
	 */
	WrongAnimal(const WrongAnimal& other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * @param other WrongAnimal object to assign from.
	 * @return Reference to the current WrongAnimal object.
	 */
	WrongAnimal& operator=(const WrongAnimal& other);

	/**
	 * @brief Destructor.
	 *
	 * This destructor is intentionally not virtual because this class is part
	 * of the "wrong" example.
	 */
	~WrongAnimal(void);

	/**
	 * @brief Get the wrong animal type.
	 *
	 * @return The stored type.
	 */
	std::string getType(void) const;

	/**
	 * @brief Print the wrong animal sound.
	 *
	 * This function is intentionally not virtual.
	 */
	void makeSound(void) const;
};

#endif
