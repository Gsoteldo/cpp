/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:29:32 by gabo              #+#    #+#             */
/*   Updated: 2025/08/04 15:01:53 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*############################################################################*/
/*####################### CONSTRUCTORS AND DESTRUCTORS #######################*/
/*############################################################################*/

FragTrap::FragTrap() : ClapTrap("Legendary Unit") {
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " has entered the game." << std::endl;
	std::cout << "It might just be... legendary.";
	std::cout << std::endl << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " has entered the game." << std::endl;
	std::cout << "It might just be... legendary.";
	std::cout << std::endl << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
	_name = fragTrap._name;
	_hitPoint = fragTrap._hitPoint;
	_energyPoint = fragTrap._energyPoint;
	_attackDamage = fragTrap._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
	if (this != &fragTrap ) {
		_name = fragTrap._name;
		_hitPoint = fragTrap._hitPoint;
		_energyPoint = fragTrap._energyPoint;
		_attackDamage = fragTrap._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " left the building like a true bro." << std::endl;
	std::cout << "It's not goodbye... it’s challenge accepted somewhere else." << std::endl;
}

/*###########################################################################*/
/*################################# METHODS #################################*/
/*###########################################################################*/


void FragTrap::highFivesGuys() {
	
	std::cout << "Fragtrap " << _name << " stretched out his arm to high-five,";
	std::cout <<" and it was Legend... Wait a minute, dary." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const FragTrap &fragTrap) {

	out << std::endl;
	out << GREEN << "FragTrap name: " << fragTrap.getName() << DEFAULT << std::endl;
	out << "-Hit Point: " << fragTrap.getHitPoint() << std::endl;
	out << "-Energy Point: " << fragTrap.getEnergyPoint() << std::endl;
	out << "-Attack Damage: " << fragTrap.getAttackDamage() << std::endl;
	
	
	return (out);
}