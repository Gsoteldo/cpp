/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:28:33 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 17:57:31 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

// El ostringstream es una clase de C++ que permite construir cadenas de texto de manera eficiente.
// Ya que permite concatenar diferentes tipos de datos (como enteros, cadenas, etc.) en una sola cadena de texto.

Zombie* zombieHorde( int N, std::string name ){
	
	Zombie* zHorde = new Zombie[N];


	for (int i = 0; i < N; i++) {
		std::ostringstream oss; 
  		oss << i; 
		std::string iStr = oss.str(); 
		zHorde[i].setName(name + " " + iStr);
	}
	
	return (zHorde);
}