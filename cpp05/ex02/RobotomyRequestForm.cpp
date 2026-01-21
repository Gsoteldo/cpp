/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:08:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2026/01/21 20:34:28 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm("Robotomy Request Form", 72, 45), _target(name) {
	std::cout << "The "<< _name << " for your " << _target << " was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this != & obj) {
		_isSigned = obj._isSigned;
		_toSign = obj._toSign;
		_toExecute = obj._toExecute;
		_target = obj._target;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::execute(Bureaucrat const& executor) const {

	// if (this->_isSigned == false)
	// 	throw FormNotSigned();
	// if (executor.getGrade() > this->_toExecute)
	// 	throw GradeTooLowException();
	AForm::execute(executor);

	srand(time(NULL));
	int num =  1 + (rand() % 100);

	if (num % 2 == 0) {
		std::cout << "The " << _name << " for " << _target << " was 100%% successful." << std::endl;
	} else {
		std::cout << "The " << _name << " for " << _target << " was failed" << std::endl;
	}
}