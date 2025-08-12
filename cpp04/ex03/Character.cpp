/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:18:15 by gabo              #+#    #+#             */
/*   Updated: 2025/08/12 19:55:48 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default"), _numUnequipped(0) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	// for (int i = 0; i < 100; i++)
	// 	_unequipped[i] = NULL;
}

Character::Character(const std::string &name) : _name(name), _numUnequipped(0) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	// for (int i = 0; i < 100; i++)
	// 	_unequipped[i] = NULL;
}

Character::Character(const Character &src) : _name(src._name), _numUnequipped(0) {
    // Copiar inventario
    for (int i = 0; i < 4; ++i) {
        if (src._inventory[i])
            _inventory[i] = src._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    
    // No copiar materias unequip (cada personaje gestiona las suyas)
    for (int i = 0; i < 100; ++i)
        _unequipped[i] = NULL;
}

Character &Character::operator=(const Character &character) {
    if (this != &character) {
        _name = character._name;
        
        // 1. Liberar inventario actual
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
        
        // 2. Liberar lista unequip actual
        for (int i = 0; i < _numUnequipped; ++i) {
            delete _unequipped[i];
            _unequipped[i] = NULL;
        }
        _numUnequipped = 0;
        
        // 3. Copiar inventario del otro personaje
        for (int i = 0; i < 4; ++i) {
            if (character._inventory[i])
                _inventory[i] = character._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; ++i)
		delete _inventory[i];
	for (int i = 0; i < _numUnequipped; ++i)
		delete _unequipped[i];
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *materia) {
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = materia->clone();
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
	_unequipped[_numUnequipped] = _inventory[id];
    _numUnequipped++;
	_inventory[id] = NULL;
}

void Character::use(int id, ICharacter &target) {
	if (id < 0 || id > 3) {
		std::cout << "Index is not between 0 and 4";
		std::cout << std::endl;
		return;
	}

	if (_inventory[id] == NULL) {
		std::cout << "Nothing to use in slot " << id;
		std::cout << ", are you blind?";
		std::cout << std::endl;
		return;
	}

	_inventory[id]->use(target);
}