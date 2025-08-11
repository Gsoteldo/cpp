/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:18:15 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 21:44:24 by gsoteldo         ###   ########.fr       */
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

Character &Character::operator=(const Character &character) {
	if (this != &character) {
		_name = character._name;
		for (int i = 0; i < 4; ++i) {
			delete _inventory[i];
			if (character._inventory[i])
				_inventory[i] = character._inventory[i]->clone();
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
	std::cout << "Inventory is full, cannot equip " << materia->getType();
	std::cout << std::endl;
}

void Character::unequip(int id) {
	if (id < 0 || id > 3) {
		std::cout << "Index is not between 0 and 4";
		std::cout << std::endl;
	}

	if (_inventory[id] == NULL) {
		std::cout << "Nothing to unequip in " << id;
		std::cout << ", are you blind?";
		std::cout << std::endl;
		
	} else {
		std::cout << "The element " <<  _inventory[id]->getType();
		std::cout << "in index " << id << "unequiped";
		std::cout << std::endl;
	}
	_inventory[id] = NULL;
}