/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:18:15 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 17:34:37 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &character) : _name(character._name) {
	for (int i = 0; i < 4; ++i){
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}

}

Character &Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		for (int i = 0; i < 4; ++i) {
			delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i)
		delete _inventory[i];
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *materia) {
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			return;
		}
	}
	std::cout << "Inventory is full, cannot equip " << materia->getType() << std::endl;
}