/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:40:10 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/08/04 09:52:03 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define DEFAULT "\033[0m"

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoint;
		int _energyPoint;
		int _attackDamage;
		
	public:
	
		//Constructors and Destructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &claptrap);
		~ClapTrap();
	
	
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
		std::string getName() const;
		int getHitPoint() const;
		int getEnergyPoint() const;
		int getAttackDamage() const;
};

std::ostream& operator<<(std::ostream& out, const ClapTrap &claptrap);

#endif