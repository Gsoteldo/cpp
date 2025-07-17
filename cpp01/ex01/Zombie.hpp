/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:56:08 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 17:52:21 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:
		std::string _name;


	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		/************** METHOD **************/
		void announce();



		void setName(std::string name);
		std::string getName();


};

/************* OTHER FUNCTIONS *************/

Zombie* zombieHorde( int N, std::string name );

#endif