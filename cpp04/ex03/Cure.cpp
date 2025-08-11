/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:55:57 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 21:35:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &obj) : AMateria(obj) {
	_type = obj._type;
}

Cure &Cure::operator=(const Cure &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	return *this;
}



Cure::~Cure() {}


std::string const &Cure::getType() const {
	return _type;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}


void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() <<"'s wounds *";
	std::cout << std::endl;
}

