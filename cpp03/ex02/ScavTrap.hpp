/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:20:38 by gabo              #+#    #+#             */
/*   Updated: 2025/08/04 12:52:14 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap &operator=(const ScavTrap &scavTrap);
		~ScavTrap();

		void	attack(const std::string& target);
		void guardGate();

};

std::ostream& operator<<(std::ostream& out, const ScavTrap &scavTrap);

#endif