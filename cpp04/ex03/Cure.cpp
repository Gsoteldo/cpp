/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:55:57 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 17:30:06 by gabo             ###   ########.fr       */
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
	return _type; // Returns the materia type
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}


void Cure::use(ICharacter& target) {
	// std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	// AMateria::use(target);
	(void)target;
	std::cout << "* heals " << "Someone" << "'s wounds with a Cure spell *" << std::endl;
}

