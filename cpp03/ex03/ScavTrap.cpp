/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:20:41 by gabo              #+#    #+#             */
/*   Updated: 2025/08/04 13:43:41 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*############################################################################*/
/*####################### CONSTRUCTORS AND DESTRUCTORS #######################*/
/*############################################################################*/

ScavTrap::ScavTrap() : ClapTrap("Unknown") {
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;

	std::cout << _name << " Robot: built and ready to serve" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;

	std::cout << _name << " Robot: built and ready to serve" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap) {
	_name = scavTrap._name;
	_hitPoint = scavTrap._hitPoint;
	_energyPoint = scavTrap._energyPoint;
	_attackDamage = scavTrap._attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
	if (this != &scavTrap ) {
		_name = scavTrap._name;
		_hitPoint = scavTrap._hitPoint;
		_energyPoint = scavTrap._energyPoint;
		_attackDamage = scavTrap._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << _name << " Robot: destroyed and he can see the end approaching." << std::endl;
}

/*###########################################################################*/
/*################################# METHODS #################################*/
/*###########################################################################*/

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoint <= 0) {
		std::cout << "ScavTrap " << _name;
		std::cout << " is too injured, cannot attack";
		std::cout << std::endl;
		return ;
	}
	else if (_energyPoint <= 0) {
		std::cout << "ScavTrap " << _name;
		std::cout << " is too exhausted, cannot attack";
		std::cout << std::endl;
		return ;
	}

	(_energyPoint)--;
	
	std::cout << "ScavTrap " << this->getName();
	std::cout << RED << " attacks " << target << DEFAULT;
	std::cout << ", with a shield and makes " << this->getAttackDamage() << " points of damage! ";
	std::cout << "It is a good robot." << std::endl;
}

void	ScavTrap::guardGate() {
	if (_hitPoint <= 0) {
		std::cout << "ScavTrap " << _name;
		std::cout << " is too injured, cannot guard the gate";
		std::cout << std::endl;
		return ;
	}
	else if (_energyPoint <= 0) {
		std::cout << "ScavTrap " << _name;
		std::cout << " is too exhausted, cannot guard the gate";
		std::cout << std::endl;
		return ;
	}
	(_energyPoint)--;

	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate Keeper mode." << std::endl;
	std::cout << "It will guard the gate with its life!";
	std::cout << std::endl;
}


std::ostream& operator<<(std::ostream& out, const ScavTrap &scavTrap) {

	out << std::endl;
	out << GREEN << "ScavTrap name: " << scavTrap.getName() << DEFAULT << std::endl;
	out << "-Hit Point: " << scavTrap.getHitPoint() << std::endl;
	out << "-Energy Point: " << scavTrap.getEnergyPoint() << std::endl;
	out << "-Attack Damage: " << scavTrap.getAttackDamage() << std::endl;
	
	
	return (out);
}