/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:15:21 by gabo              #+#    #+#             */
/*   Updated: 2025/08/06 11:19:38 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "It is a Cat!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	_type = cat._type;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this != &cat)
		_type = cat._type;
	return (*this);
}

Cat::~Cat() {}

void Cat::makeSound() {
	std::cout << "Meeeooow" << std::endl;
}