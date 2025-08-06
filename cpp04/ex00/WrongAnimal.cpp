/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:47:06 by gabo              #+#    #+#             */
/*   Updated: 2025/08/06 11:54:02 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Unknown Animal") {
	std::cout << "I can't see the animal but there is something";
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {}
	
WrongAnimal::WrongAnimal(const WrongAnimal &name) {
	_type = name._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &name) {
	if (this != &name)
		_type = name._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {}

void	WrongAnimal::makeSound() {
	std::cout << _type << " makes an inaudible sound" << std::endl;
}