/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:23:42 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 13:00:54 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;	
	public:
		Dog();
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		~Dog();
	
		Brain *getBrain();
		
		void makeSound() const;
};

#endif