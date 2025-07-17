/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:02:39 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 19:16:27 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() : _name("Someone"), _weapon("none") {}

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {
	std::cout << this->_name << "was destructed" << std::endl;
}

std::string HumanA::getName() {
	return (_name);
}

void HumanA::setName(std::string name) {
	_name = name;
}


