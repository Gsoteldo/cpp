/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:55:09 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 17:03:19 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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