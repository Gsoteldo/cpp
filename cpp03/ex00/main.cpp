/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:34:52 by gabo              #+#    #+#             */
/*   Updated: 2025/08/04 09:59:38 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	
	ClapTrap a;
	ClapTrap b("Eric");

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.attack("Pepe");
	b.attack("gafa");
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.beRepaired(1);
	
	std::cout << a << std::endl;

	a.beRepaired(20);

	std::cout << a << std::endl;

	a.beRepaired(5);


	a.takeDamage(10);
	b.takeDamage(2);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.takeDamage(10);
	b.takeDamage(2);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.takeDamage(10);

	a.beRepaired(0);
	
	std::cout << std::endl;

	return 0;
}