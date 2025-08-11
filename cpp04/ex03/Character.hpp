/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:18:30 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 21:30:36 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
public:
	Character();
	Character(std::string const &name);
	Character(Character const &src);
	Character &operator=(Character const &rhs);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	// void use(int idx, ICharacter &target);
};

#endif