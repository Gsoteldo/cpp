/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:00:01 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 19:15:19 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

class HumanA
{
	private:
		std::string _name;
		Weapon _weapon;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();

		std::string getName();
		void setName(std::string name);
};

#endif