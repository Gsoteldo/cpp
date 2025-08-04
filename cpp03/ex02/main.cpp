/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:34:52 by gabo              #+#    #+#             */
/*   Updated: 2025/08/04 14:09:07 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	
	/*############################################################################*/
	/*################################ TESTS EX00 ################################*/
	/*############################################################################*/
	{
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
	}

	/*############################################################################*/
	/*################################ TESTS EX01 ################################*/
	/*############################################################################*/
	
	std::cout << std::endl;
	std::cout << "-------------Testing ScavTrap class-------------" << std::endl;
	{
		
		ClapTrap a("Eric");
		ScavTrap b("Gabo");
		ScavTrap c;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.attack("Pepe");
		b.attack("gafa");
		c.attack("gabo");

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.beRepaired(1);
		b.beRepaired(1);
		c.beRepaired(1);


		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		a.beRepaired(20);
		b.beRepaired(20);
		c.beRepaired(20);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.takeDamage(10);
		b.takeDamage(2);
		c.takeDamage(2);

		a.takeDamage(0);
		b.takeDamage(0);
		c.takeDamage(200);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		b.guardGate();
		c.guardGate();

		
	}

	/*############################################################################*/
	/*################################ TESTS EX01 ################################*/
	/*############################################################################*/

	std::cout << std::endl;
	std::cout << "-------------Testing FragTrap class-------------" << std::endl;
	{
		FragTrap a("Eric");
		FragTrap b("Bartney");
		FragTrap c;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		b.highFivesGuys();

		
	}

	return 0;
}