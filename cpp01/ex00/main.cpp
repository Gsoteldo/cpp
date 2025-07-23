/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:39:14 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/23 21:55:40 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



/*
	Diferencia entre newZombie y randomChump:
	newZombie crea un objeto Zombie en el heap y devuelve un puntero a él.
	util para crear zombies que se mantendrán en memoria hasta que se eliminen explícitamente.
	
	randomChump crea un objeto Zombie en el stack y lo destruye automáticamente al salir del scope.
	util para crear zombies temporales que no necesitan persistir más allá de su uso inmediato.

	Heap: memoria dinámica, se usa con new y delete. Se debe liberar manualmente.
	Se utiliza para objetos que necesitan persistir más allá del scope actual.
	
	Stack: memoria automática, se usa con variables locales. Se libera automáticamente al salir del scope.
	Se utiliza para objetos temporales que no necesitan persistir más allá de su uso inmediato.

*/
int main()
{
	Zombie *z= NULL;

	std::cout << "Prueba de zombies" << std::endl;
	
	z = newZombie("Alice"); // Devuelve un puntero a un Zombie creado en el heap
	randomChump("Bob");	// Crea un Zombie en el stack y lo destruye automáticamente al salir del scope
	
	//abbviuaheruyvi
	delete z; // Elimina el Zombie creado en el heap
	return (0);	
}