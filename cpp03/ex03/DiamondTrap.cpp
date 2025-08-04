/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:04 by gabo              #+#    #+#             */
/*   Updated: 2025/08/04 16:05:52 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*############################################################################*/
/*####################### CONSTRUCTORS AND DESTRUCTORS #######################*/
/*############################################################################*/

DiamondTrap::DiamondTrap() : 
	ClapTrap("Unknown_clap_name"),
	FragTrap(),
	ScavTrap(),
	_name("Unknown")
{
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_hitPoint;
	_attackDamage = FragTrap::_attackDamage;
	
std::cout << "=== DiamondTrap " << _name << " ===" << std::endl;
std::cout << "Awakened from code, caught between FragTrap and ScavTrap." << std::endl;
std::cout << "A puzzle of logic stitched together — a digital Frankenstein." << std::endl;
	// std::cout << "It looks at its hands, then at the sky, and wonders if it will ever find its place in the world." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(),
	ScavTrap(),
	_name(name)
{
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_hitPoint;
	_attackDamage = FragTrap::_attackDamage;

std::cout << "=== DiamondTrap " << _name << " ===" << std::endl;
std::cout << "Awakened from code, caught between FragTrap and ScavTrap." << std::endl;
std::cout << "A puzzle of logic stitched together — a digital Frankenstein." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap): ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap) {
	_name = diamondTrap._name;
	_hitPoint = diamondTrap._hitPoint;
	_energyPoint = diamondTrap._energyPoint;
	_attackDamage = diamondTrap._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	if (this != &diamondTrap) {
		_name = diamondTrap._name;
		_hitPoint = diamondTrap._hitPoint;
		_energyPoint = diamondTrap._energyPoint;
		_attackDamage = diamondTrap._attackDamage;
	}
	
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " takes its final breath..." << std::endl;
    std::cout << "'Was I ever truly complete?' echoes into the void as memory deallocates." << std::endl;
}

/*###########################################################################*/
/*################################# METHODS #################################*/
/*###########################################################################*/

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap: " << _name << std::endl;
    std::cout << "But deep inside, my ClapTrap identity is: " << ClapTrap::_name << std::endl;
}



std::ostream& operator<<(std::ostream& out, const DiamondTrap &diamondtrap) {
	out << std::endl;
	out << GREEN << "DiamondTrap name: " << diamondtrap.getName() << DEFAULT << std::endl;
	out << "-Hit Point: " << diamondtrap.getHitPoint() << std::endl;
	out << "-Energy Point: " << diamondtrap.getEnergyPoint() << std::endl;
	out << "-Attack Damage: " << diamondtrap.getAttackDamage() << std::endl;
    return out;
}