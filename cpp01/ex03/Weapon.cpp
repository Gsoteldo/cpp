/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:43:01 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 18:58:24 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon () :  _type("none") {}

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {
	std::cout << this->_type << " weapon was destroyed" << std::endl;
}

std::string Weapon::getType() {
	return (_type);
}

void Weapon::setType(std::string type) {
	_type = type;
}
