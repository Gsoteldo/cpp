/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:30:13 by gabo              #+#    #+#             */
/*   Updated: 2026/01/21 20:35:06 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm("Presidential Pardon Form", 25, 5), _target(name) {
	std::cout << "The presidential Pardon Form for your " << _target << "was created";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this != & obj) {
		_isSigned = obj._isSigned;
		_toSign = obj._toSign;
		_toExecute = obj._toExecute;
		_target = obj._target;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	AForm::execute(executor);

	std::cout << executor << " has been pardoned by Zaphod Beeblebrox.";
	std::cout << std::endl;	
}