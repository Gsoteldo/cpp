/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:44:48 by gabo              #+#    #+#             */
/*   Updated: 2025/08/12 19:54:45 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const &AMateria::getType() const {
	return _type; // Returns the materia type
}

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target) {
	(void)target;
	// std::cout <<  "* shoots an ice bolt at " << target.getName() << " *";
	// std::cout << std::endl;
}