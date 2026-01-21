/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:01:44 by gabo              #+#    #+#             */
/*   Updated: 2026/01/22 00:35:52 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	formName[0] = "shrubbery creation";
	formName[1] = "robotomy request";
	formName[2] = "presidential pardon";
	forms[0] = &Intern::CreateShrubberyForm;
	forms[1] = &Intern::CreateRobotomyForm;
	forms[2] = &Intern::CreatePresidentialForm; 
}
	
Intern::Intern(const Intern &obj) {
	for (int i = 0; i < 3; i++) {	
		formName[i] = obj.formName[i];
		forms[i] = obj.forms[i];
	}
}
	
Intern &Intern::operator=(const Intern &obj){
	if (this != &obj) {
		for (int i = 0; i < 3; i++) {
			formName[i] = obj.formName[i];
			forms[i] = obj.forms[i];
		}
	}
	return (*this);
}

Intern::~Intern() {}


AForm *Intern::CreateShrubberyForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::CreateRobotomyForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::CreatePresidentialForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

int Intern::getIndex(const std::string &formType) {
	for (int i = 0; i < 3; i++) {
		if (formType == formName[i]) {
			return (i);
		}
	}
	return (-1);
}

AForm *Intern::makeForm(const std::string &formType, const std::string &target) {
	int index = getIndex(formType);

	if (index == -1) {
		std::cerr << "Intern could not create form because form type is unknown: " << formType << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << formType << " ." << std::endl;
	
	return ((this->*forms[index])(target));
}