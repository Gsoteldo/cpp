/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:49:04 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 17:24:05 by gabo             ###   ########.fr       */
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