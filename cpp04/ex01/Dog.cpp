/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:28:32 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 12:33:49 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "It's a dog!" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog) {
	_type = dog._type;
	_brain = new Brain(*dog._brain);
	
}

Dog &Dog::operator=(const Dog &dog) {
	if (this != &dog) {
		_type = dog._type;
		delete _brain;
		_brain = new Brain(*dog._brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete _brain;
}

void Dog::makeSound() {
	std::cout << "Woof Woof";
	std::cout << std::endl;
}

Brain *Dog::getBrain() {
	return (_brain);
	
}