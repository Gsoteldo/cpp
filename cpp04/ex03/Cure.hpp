/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:55:09 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 21:34:12 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure &obj);
		Cure &operator=(const Cure &obj);
		~Cure();

		std::string const &getType() const;

		AMateria* clone() const;

		void use(ICharacter& target);
};