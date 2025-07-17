/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:41:03 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 18:48:16 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string _type;
		
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();


		std::string getType();
		void setType(std::string type);
};




#endif