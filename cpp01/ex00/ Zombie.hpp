/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Zombie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:41:58 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/05/11 20:03:03 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {

	private:
		std::string name;


	public:
		Zombie();
		~Zombie();
		void announce();


};

#endif