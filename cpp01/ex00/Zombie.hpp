/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:56:08 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 17:04:41 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:
		std::string name;


	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		/************** METHOD **************/
		void announce();


};

/************* OTHER FUNCTIONS *************/

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif