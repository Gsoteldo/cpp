/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:39:14 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 18:04:27 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



/*
	Diferencia entre new y new[]:
	new se utiliza para asignar memoria para un único objeto,
	mientras que new[] se utiliza para asignar memoria para un array de objetos.

	Diferencia entre delete y delete[]:
	delete se utiliza para liberar la memoria asignada a un único objeto, 
	mientras que delete[] se utiliza para liberar la memoria asignada a un array
	de objetos.
*/


int main()
{
	Zombie *z = NULL;

	z = zombieHorde(3, "Bob");

	for (int i = 0; i < 3; i++) {
		z[i].announce();
	}

	delete[] z; //Con los corchetes se libera toda la memoria asignada para el array.
	return (0);	
}