/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:50:43 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 13:02:57 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
std::cout << "--- Intento de instanciar Animal (debe fallar si descomentas) ---\n";
    // Animal a;          // Error: Animal es abstracta
    // Animal* a = new Animal(); // Error: no se puede instanciar

    std::cout << "\n--- Creación de Dog y Cat ---\n";
    Dog dog1;
    Cat cat1;

    dog1.getBrain()->setIdea(0, "I want to play");
    cat1.getBrain()->setIdea(0, "I want to sleep");

    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Test de deep copy con Dog ---\n";
    Dog dog2 = dog1; // copy constructor
    dog1.getBrain()->setIdea(0, "I want to run");

    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Test de deep copy con Cat ---\n";
    Cat cat2;
    cat2 = cat1;     // assignment operator
    cat1.getBrain()->setIdea(0, "I want to hunt");

    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Array de Animal* con Dog y Cat ---\n";
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}