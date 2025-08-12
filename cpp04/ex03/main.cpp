/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:38:19 by gabo              #+#    #+#             */
/*   Updated: 2025/08/12 16:23:45 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "===== TEST 1: Crear y usar materias =====" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
	delete tmp; // Evitar memory leak

	
    tmp = src->createMateria("cure");
    me->equip(tmp);
	delete tmp; // Evitar memory leak

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n===== TEST 2: Tipo inexistente =====" << std::endl;
    tmp = src->createMateria("fire");
    if (!tmp) std::cout << "No materia created for type 'fire'" << std::endl;

    std::cout << "\n===== TEST 3: Inventario lleno =====" << std::endl;
	tmp = src->createMateria("ice");
    me->equip(tmp);
	delete tmp; // Evitar memory leak
	
	tmp = src->createMateria("cure");
    me->equip(tmp);
	delete tmp; // Evitar memory leak

    tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp; // Evitar memory leak

    std::cout << "\n===== TEST 4: Uso con índice inválido =====" << std::endl;
    me->use(10, *bob); // No debe crashear
    me->use(-1, *bob); // No debe crashear

    std::cout << "\n===== TEST 5: Unequip sin borrar =====" << std::endl;
    me->unequip(0); // No borrar, pero liberar referencia
    me->use(0, *bob); // Ya no debería hacer nada

    std::cout << "\n===== TEST 6: Copia profunda =====" << std::endl;
    Character original("original");
	tmp = src->createMateria("ice");
    original.equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
    original.equip(tmp);
	delete tmp;

    Character copia = original; // Copy constructor
    original.use(0, *bob);
    copia.use(0, *bob);

    // Cambiamos materia en original para ver si afecta a copia
    original.unequip(0);
    original.use(0, *bob); // No hace nada
    copia.use(0, *bob); // Debe seguir funcionando

    std::cout << "\n===== TEST 7: MateriaSource lleno =====" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); // Ya debe estar lleno

    delete me;
    delete bob;
    delete src;

    std::cout << "\n===== TESTS COMPLETADOS =====" << std::endl;
    return 0;
}