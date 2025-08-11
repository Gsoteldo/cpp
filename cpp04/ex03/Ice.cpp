/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:49:04 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 21:27:02 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &obj) : AMateria(obj) {
	_type = obj._type;
}

Ice &Ice::operator=(const Ice &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}

Ice::~Ice() {}

std::string const &Ice::getType() const {
	return _type; // Returns the materia type
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
}