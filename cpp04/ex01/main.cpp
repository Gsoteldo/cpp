/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:50:43 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 12:40:17 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	
    // 1. Crear array de punteros a Animal
    const int size = 4;
    Animal* animals[size];

    // 2. Llenar mitad perros y mitad gatos
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Test de sonidos ---\n";
    // 3. Probar que cada uno hace su sonido
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Test de Brain deep copy ---\n";
    // 4. Probar deep copy con Dog
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want food");
    Dog dog2 = dog1;  // constructor de copia
    dog1.getBrain()->setIdea(0, "I want to play");

    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    // 5. Probar deep copy con Cat (similar)
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Want to sleep");
    Cat cat2;
    cat2 = cat1; // operador de asignación
    cat1.getBrain()->setIdea(0, "I want to hunt");

    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

    // 6. Liberar memoria del array de animales
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}