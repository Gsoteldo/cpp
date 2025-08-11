/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:57:11 by gabo              #+#    #+#             */
/*   Updated: 2025/08/06 11:57:53 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "It is a WrongCat!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat) {
	_type = cat._type;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
	if (this != &cat)
		_type = cat._type;
	return (*this);
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() {
	std::cout << "Meeeooow" << std::endl;
}