/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:21:10 by gabo              #+#    #+#             */
/*   Updated: 2025/07/18 11:10:15 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"
#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();

		std::string getName();
		void setName(std::string name);
		void attack();
		void setWeapon(Weapon& weapon);
};

#endif