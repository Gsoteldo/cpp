/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:32:04 by gabo              #+#    #+#             */
/*   Updated: 2025/08/12 12:32:42 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &rhs);
		void learnMateria(AMateria *m);
		AMateria *createMateria(const std::string &type);
};

#endif