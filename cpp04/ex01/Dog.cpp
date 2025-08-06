/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:28:32 by gabo              #+#    #+#             */
/*   Updated: 2025/08/06 11:05:26 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "It's a dog!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
	_type = dog._type;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this != &dog)
		_type = dog._type;
	return (*this);
}

Dog::~Dog() {}

void Dog::makeSound() {
	std::cout << "Woof Woof";
	std::cout << std::endl;
}