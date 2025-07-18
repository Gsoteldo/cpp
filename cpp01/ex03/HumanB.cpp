/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:20:12 by gabo              #+#    #+#             */
/*   Updated: 2025/07/18 11:10:13 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() : _name("Someone") {}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {
	std::cout << this->_name << " was destructed" << std::endl;
}

std::string HumanB::getName() {
	return (_name);
}

void HumanB::setName(std::string name) {
	_name = name;
}

void HumanB::attack() {
	//<name> attacks with their <weapon type>
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon, he can't attack" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}
