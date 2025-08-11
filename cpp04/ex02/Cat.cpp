/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:15:21 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 13:01:15 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "It is a Cat!" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	_type = cat._type;
	_brain = new Brain(*cat._brain);
}

Cat &Cat::operator=(const Cat &cat) {
	if (this != &cat) {
		_type = cat._type;
		delete _brain;
		_brain = new Brain(*cat._brain);	
	}
	return (*this);
}

Cat::~Cat() {
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meeeooow" << std::endl;
}

Brain *Cat::getBrain() {
	return (_brain);
	
}