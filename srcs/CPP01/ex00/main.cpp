/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:54:00 by fyudris           #+#    #+#             */
/*   Updated: 2026/06/27 15:57:23 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie;

	heapZombie = new Zombie("HeapZombie");
	heapZombie->announce();
	
	randomChump("StackZombie");

	delete heapZombie;
	return (0);
}