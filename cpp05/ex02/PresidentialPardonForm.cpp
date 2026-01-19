/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:30:13 by gabo              #+#    #+#             */
/*   Updated: 2025/10/15 21:08:02 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this != & obj) {
		_isSigned = obj._isSigned;
		_toSign = obj._toSign;
		_toExecute = obj._toExecute;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const {

	if (this->_isSigned == true && executor.getGrade() <= this->_toExecute) {
		std::cout << executor << " has been pardoned by Zaphod Beeblebrox.";
		std::cout << std::endl;	
	} else {
		throw FormNotSigned();	
	}
}