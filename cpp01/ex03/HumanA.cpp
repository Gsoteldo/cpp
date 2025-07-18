/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:02:39 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/18 11:31:02 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() : _name("Someone"), _weapon(NULL) {}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon) {}

HumanA::~HumanA() {
	std::cout << this->_name << " was destructed" << std::endl;
}

std::string HumanA::getName() {
	return (_name);
}

void HumanA::setName(std::string name) {
	_name = name;
}

void HumanA::attack() {
	//<name> attacks with their <weapon type>
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}