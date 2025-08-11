/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:15:11 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 13:02:17 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Unknown Animal") {
	std::cout << "I can't see the animal but there is something";
	std::cout << std::endl;
}

Animal::Animal(std::string type) : _type(type) {}

Animal::Animal(const Animal &animal) {
	_type = animal._type;
} 

Animal &Animal::operator=(const Animal &animal) {
	if (this != &animal)
		_type = animal._type;
	return (*this);
}
 
Animal::~Animal() {} 

void	Animal::makeSound() const {
	std::cout << _type << " makes an inaudible sound" << std::endl;
}