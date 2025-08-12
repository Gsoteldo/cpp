/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:33:36 by gabo              #+#    #+#             */
/*   Updated: 2025/08/12 14:31:21 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	for (int i = 0; i < 4; ++i) {
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; ++i) {
			delete _materias[i];
			if (rhs._materias[i])
				_materias[i] = rhs._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
		delete _materias[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (!_materias[i]) {
			_materias[i] = m;
			return;
		}
	}
	delete m; // Evitar memory leak si no hay espacio
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; ++i) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone(); // Clonar la materia antes de devolverla
		}
	}
	return NULL; // Return NULL if no matching materia is found
	
}