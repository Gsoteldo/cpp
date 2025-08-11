/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:44:48 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 17:20:37 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const {
	return _type; // Returns the materia type
}

// AMateria::~AMateria() {}

// void AMateria::use(ICharacter& target) {
// 	std::cout << "Using " << _type << " on " << target.getName() << std::endl;
// }