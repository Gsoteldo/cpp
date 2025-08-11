/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:45:36 by gabo              #+#    #+#             */
/*   Updated: 2025/08/11 12:31:52 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {};

Brain::Brain(const Brain &obj) {
	for (int i = 0; i < 100; ++i)
		_ideas[i] = obj._ideas[i];
};

Brain &Brain::operator=(const Brain &obj) {
	if (this != &obj) {
		for (int i = 0; i < 100; ++i)
			_ideas[i] = obj._ideas[i];
	}
	return (*this);
};

std::string Brain::getIdea(int index) {
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string str) {
	if (index >= 0 && index <= 100)
		_ideas[index] = str;
}

Brain::~Brain() {};