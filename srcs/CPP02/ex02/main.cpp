/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:57:46 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/05 19:52:49 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

static void	printSection(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main(void)
{
	printSection("Basic construction and output");

	Fixed a;
	Fixed b(10);
	Fixed c(2);
	Fixed d(5.05f);
	Fixed e(10);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	printSection("Comparison operators");

	std::cout << "b > c  : " << (b > c) << std::endl;
	std::cout << "b < c  : " << (b < c) << std::endl;
	std::cout << "b >= e : " << (b >= e) << std::endl;
	std::cout << "b <= e : " << (b <= e) << std::endl;
	std::cout << "b == e : " << (b == e) << std::endl;
	std::cout << "b <= d : " << (b <= d) << std::endl;

	printSection("Arithmetic operators");

	std::cout << "b + c = " << (b + c) << std::endl;
	std::cout << "b - c = " << (b - c) << std::endl;
	std::cout << "b * c = " << (b * c) << std::endl;
	std::cout << "b / c = " << (b / c) << std::endl;

	std::cout << "d * c = " << (d * c) << std::endl;
	std::cout << "d / c = " << (d / c) << std::endl;

	printSection("Pre-increment");

	std::cout << "a before ++a : " << a << std::endl;
	std::cout << "++a returns  : " << ++a << std::endl;
	std::cout << "a after ++a  : " << a << std::endl;

	printSection("Post-increment");

	std::cout << "a before a++ : " << a << std::endl;
	std::cout << "a++ returns  : " << a++ << std::endl;
	std::cout << "a after a++  : " << a << std::endl;

	printSection("Pre-decrement");

	std::cout << "a before --a : " << a << std::endl;
	std::cout << "--a returns  : " << --a << std::endl;
	std::cout << "a after --a  : " << a << std::endl;

	printSection("Post-decrement");

	std::cout << "a before a-- : " << a << std::endl;
	std::cout << "a-- returns  : " << a-- << std::endl;
	std::cout << "a after a--  : " << a << std::endl;

	printSection("Static min/max with non-const objects");

	Fixed x(42.42f);
	Fixed y(21.21f);

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "Fixed::min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "Fixed::max(x, y) = " << Fixed::max(x, y) << std::endl;

	printSection("Static min/max with const objects");

	const Fixed constX(100);
	const Fixed constY(200);

	std::cout << "constX = " << constX << std::endl;
	std::cout << "constY = " << constY << std::endl;
	std::cout << "Fixed::min(constX, constY) = "
			  << Fixed::min(constX, constY) << std::endl;
	std::cout << "Fixed::max(constX, constY) = "
			  << Fixed::max(constX, constY) << std::endl;

	printSection("Subject test");

	Fixed subjectA;
	Fixed const subjectB(Fixed(5.05f) * Fixed(2));

	std::cout << subjectA << std::endl;
	std::cout << ++subjectA << std::endl;
	std::cout << subjectA << std::endl;
	std::cout << subjectA++ << std::endl;
	std::cout << subjectA << std::endl;
	std::cout << subjectB << std::endl;
	std::cout << Fixed::max(subjectA, subjectB) << std::endl;

	return (0);

}
