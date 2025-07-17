/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:45:03 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 17:52:10 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() : _name ("anonymous zombie") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}

std::string Zombie::getName() {
	return (_name);
}
