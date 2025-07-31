/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:40:13 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/31 18:15:55 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/*############################################################################*/
/*####################### CONSTRUCTORS AND DESTRUCTORS #######################*/
/*############################################################################*/

ClapTrap::ClapTrap() :
	_name("Nameless"),
	_hitPoint(10),
	_energyPoint(10),
	_attackDamage(0)
{
	std::cout << _name << " Robot: built and ready to go" << std::endl;
}



ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitPoint(10),
	_energyPoint(10),
	_attackDamage(0)  
{
	std::cout << _name << " Robot: built and ready to go" << std::endl;
}



ClapTrap::ClapTrap(const ClapTrap &claptrap) {

	_name = claptrap._name;
	_hitPoint = claptrap._hitPoint;
	_energyPoint = claptrap._energyPoint;
	_attackDamage = claptrap._attackDamage;
	
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {

	if (this != &claptrap) {
		_name = claptrap._name;
		_hitPoint = claptrap._hitPoint;
		_energyPoint = claptrap._energyPoint;
		_attackDamage = claptrap._attackDamage;
	}

	return (*this);
}

ClapTrap::~ClapTrap() {
	
	std::cout << _name << " Robot: destroyed, but not the end" << std::endl;	
}

/*###########################################################################*/
/*################################# METHODS #################################*/
/*###########################################################################*/

void	ClapTrap::attack(const std::string& target) {

	if (_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name << " is too injured, cannot attack";
		return ;
	}
	else if (_energyPoint <= 0) {
		std::cout << "ClapTrap " << _name << " is too exhausted, cannot attack";
		return ;
	}
	
	(_energyPoint)--;

	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!";
	std::cout << "It is a good robot." << std::endl;
}

static bool checkRepaired(const ClapTrap &claptrap, int amount) {
	
	if (amount == 0) {
		std::cout << "ClapTrap " << claptrap.getName() << " was attacked with an intensity of 0.";
		std::cout << " The robot did not even move. It was hurt more by the uncomfortable silence.";
		std::cout << std::endl;
		return (false);
	}
	if (claptrap.getHitPoint() <= 0) {
		std::cout << "ClapTrap " << claptrap.getName() << " is too injured, cannot be repaired";
		std::cout << std::endl;
		return (false);
	}
	else if (claptrap.getEnergyPoint() <= 0) {
		std::cout << "ClapTrap " << claptrap.getName() << " is too exhausted, cannot be repaired";
		std::cout << std::endl;
		return (false);
	}
	else if (claptrap.getHitPoint() >= 20) {
		std::cout << "ClapTrap " << claptrap.getName() << " is too healthy. ";
		std::cout << "Repair cancelled due to excess health.";
		std::cout << std::endl;
		return (false);
	}
	

	return (true);
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (checkRepaired(*this, amount) == false)
		return ;
	
	// if (amount == 0) {
	// 	std::cout << "ClapTrap " << _name << " was attacked with an intensity of 0.";
	// 	std::cout << " The robot did not even move. It was hurt more by the uncomfortable silence.";
	// 	std::cout << std::endl;
	// 	return ;
	// }
	// if (_hitPoint <= 0) {
	// 	std::cout << "ClapTrap " << _name << " is too injured, cannot be repaired";
	// 	std::cout << std::endl;
	// 	return ;
	// }
	// else if (_energyPoint <= 0) {
	// 	std::cout << "ClapTrap " << _name << " is too exhausted, cannot be repaired";
	// 	std::cout << std::endl;
	// 	return ;
	// }
	// else if (_hitPoint >= 20) {
	// 	std::cout << "ClapTrap " << _name << " is too healthy. ";
	// 	std::cout << "Repair cancelled due to excess health.";
	// 	std::cout << std::endl;
	// 	return ;
	// }

	(_energyPoint)--;
	if (_hitPoint + amount <= 20)
		_hitPoint += amount;
	else 
		_hitPoint = 20;

	std::cout << "ClapTrap " << _name << " is repaired and recovers " << amount;
	std::cout << " life points. " << _attackDamage << " It is a good robot." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name;
		std::cout << " It's already destroyed... and you're still trying to destroy it?";
		std::cout << " Do you think it is a zombie or what?";
		std::cout << std::endl;
		return ;
	}
	
	if (_hitPoint - amount != 0)
		_hitPoint -= amount;
	else
		_hitPoint = 0; 
}

/*###########################################################################*/
/*################################# GETTERS #################################*/
/*###########################################################################*/


std::string ClapTrap::getName() const {
	return (_name);
}

int ClapTrap::getHitPoint() const {
	return (_hitPoint);
}

int ClapTrap::getEnergyPoint() const {
	return (_energyPoint);
}

int ClapTrap::getAttackDamage() const {
	return (_attackDamage);
}



std::ostream& operator<<(std::ostream& out, const ClapTrap &claptrap) {

	out << std::endl;
	out << "claptrap name: " << claptrap.getName() << std::endl;
	out << "-Hit Point: " << claptrap.getHitPoint() << std::endl;
	out << "-Energy Point: " << claptrap.getEnergyPoint() << std::endl;
	out << "-Attack Damage: " << claptrap.getAttackDamage() << std::endl;
	
	
	return (out);
}