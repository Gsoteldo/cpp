/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:50:43 by gabo              #+#    #+#             */
/*   Updated: 2025/08/06 12:00:00 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal *animal = new Animal();
	animal->makeSound();

	std::cout << std::endl;

	Animal *dog = new Dog();
	dog->makeSound();

	Animal *cat = new Cat();
	cat->makeSound();

	WrongAnimal *wrongAnimal = new WrongAnimal();
	wrongAnimal->makeSound();

	WrongAnimal *wrongCat = new WrongCat();
	wrongCat->makeSound();
	
	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
}