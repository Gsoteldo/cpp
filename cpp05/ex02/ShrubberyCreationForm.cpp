/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:52:06 by gsoteldo          #+#    #+#             */
/*   Updated: 2026/01/21 20:34:13 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>



ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	std::cout << "The "<< _name << " for your " << _target << " was created"  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this != & obj) {
		_isSigned = obj._isSigned;
		_toSign = obj._toSign;
		_toExecute = obj._toExecute;
		_target = obj._target;
	}

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

	// if (this->_isSigned == false)
	// 	throw FormNotSigned();
	// if (executor.getGrade() > this->_toExecute)
	// 	throw GradeTooLowException();
	AForm::execute(executor);

	
	// std::string filename = this->_target + "_shrubbery";
	std::ofstream file((this->_target + "_shrubbery").c_str());
	
	if (!file.is_open()) {
		std::cerr << this->_target + "_shrubbery" << "can't be opened";
	}
	file << "       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\\n";
	file.close();
}