/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:40:13 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/08/04 14:07:21 by gabo             ###   ########.fr       */
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
	std::cout << std::endl;
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

	std::cout << "ClapTrap " << _name << RED << " attacks " << target << DEFAULT;
	std::cout << ", causing " << _attackDamage << " points of damage! ";
	std::cout << "It is a good robot." << std::endl;
}

static bool checkRepaired(const ClapTrap &claptrap, int amount) {
	
	if (amount == 0) {
		std::cout << "ClapTrap " << claptrap.getName();
		std::cout << " was attacked with an intensity of 0.";
		std::cout << " The robot did not even move.";
		std::cout << " It was hurt more by the uncomfortable silence.";
		std::cout << std::endl;
		return (false);
	}
	if (claptrap.getHitPoint() <= 0) {
		std::cout << "ClapTrap " << claptrap.getName();
		std::cout << " is too injured, cannot be repaired";
		std::cout << std::endl;
		return (false);
	}
	else if (claptrap.getEnergyPoint() <= 0) {
		std::cout << "ClapTrap " << claptrap.getName();
		std::cout << " is too exhausted, cannot be repaired";
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

	(_energyPoint)--;
	if (_hitPoint + amount <= 20)
		_hitPoint += amount;
	else 
		_hitPoint = 20;

	std::cout << YELLOW << "ClapTrap " << _name << DEFAULT;
	std::cout << " is repaired and recovers " << amount;
	std::cout << " life points. ";
	std::cout << "It is a good robot." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoint <= 0) {
		std::cout << _name;
		std::cout << YELLOW << " It's already destroyed..." << DEFAULT;
		std::cout << "and you're still trying to destroy it?";
		std::cout << " Do you think it is a zombie or what?";
		std::cout << std::endl;
		return ;
	}
	
	if (amount <= 0) {
		std::cout << _name;
		std::cout << " was attacked with an intensity of 0 or less.";
		std::cout << " The robot did not even move.";
		std::cout << " It was hurt more by the uncomfortable silence.";
		std::cout << std::endl;
		return ;
	}
	
	if (_hitPoint - amount != 0)
		_hitPoint -= amount;
	else
		_hitPoint = 0;

	std::cout << "ClapTrap " << _name << " takes ";
	std::cout << amount << " points of damage! ";
	if (_hitPoint > 0)
		std::cout << "It is still alive, but barely." << std::endl;
	else
		std::cout << "It is destroyed." << std::endl;
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
	out << GREEN << "claptrap name: " << claptrap.getName() << DEFAULT << std::endl;
	out << "-Hit Point: " << claptrap.getHitPoint() << std::endl;
	out << "-Energy Point: " << claptrap.getEnergyPoint() << std::endl;
	out << "-Attack Damage: " << claptrap.getAttackDamage() << std::endl;
	
	
	return (out);
}