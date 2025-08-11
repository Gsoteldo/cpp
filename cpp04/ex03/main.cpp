/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:38:19 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 21:32:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	AMateria *cloneCure = cure->clone();
	AMateria *cloneIce = ice->clone();
	ICharacter  *character = new Character("Bob");

	std::cout << "Materia type: " << cure->getType() << std::endl;
	std::cout << "Cloned Materia type: " << cloneCure->getType() << std::endl;
	std::cout << "Ice Materia type: " << ice->getType() << std::endl;
	std::cout << "Cloned Ice Materia type: " << cloneIce->getType() << std::endl;
	

	ice->use(*character);
	cure->use(*character);
	delete ice;
	delete cure;
	delete cloneCure;
	delete cloneIce;
	delete character;
	return (0);
}