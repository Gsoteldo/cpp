/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:47:12 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 17:23:07 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &obj);
		Ice &operator=(const Ice &obj);
		~Ice();

		std::string const &getType() const;

		AMateria* clone() const;

		void use(ICharacter& target);
};


#endif