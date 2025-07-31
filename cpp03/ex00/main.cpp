/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:34:52 by gabo              #+#    #+#             */
/*   Updated: 2025/07/31 17:25:33 by gsoteldo         ###   ########.fr       */
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


	a.getAttackDamage(10);
	b.getAttackDamage(2);

	std::cout << std::endl;

	return 0;
}