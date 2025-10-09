/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:44:35 by gabo              #+#    #+#             */
/*   Updated: 2025/10/09 17:14:46 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():  _name("Unnamed Form"), _isSigned(false), _toSign(150), _toExecute(150) {}

Form::Form(std::string name, int toSign, int toExecute): _name(name), _isSigned(false), _toSign(toSign), _toExecute(toExecute) {
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();

	std::cout << "Form: " << name << " was created" << std::endl;
	
}

Form::Form(const Form &obj): _name(obj._name), _isSigned(obj._isSigned), _toSign(obj._toSign), _toExecute(obj._toExecute) {}

Form &Form::operator=(const Form &obj){
	if (this != &obj) {
		_isSigned = obj._isSigned;
		_toSign = obj._toSign;
		_toExecute = obj._toExecute;
	}
	return (*this);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	
	return ("Grade too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	
	return ("Grade too Low");
}

std::string	Form::getName() const{
	return (_name);
}
bool	Form::getIsSigned() const{
	return (_isSigned);
}

int	Form::getToSign() const{
	return (_toSign);
}
int	Form::getToExecute() const{
	return (_toExecute);
}

void Form::beSigned(const Bureaucrat &bureau) {
	if (_toSign < bureau.getGrade())
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form &obj) {
	out << std::endl << "-------------------------------" << std::endl;
	out << "Form name: " << obj.getName() << std::endl;
	out << "Is Signed: " << obj.getIsSigned() << std::endl;
	out << "To signed is necessary: " << obj.getToSign() << " grade" << std::endl;
	out << "And to execute is necessary: " << obj.getToExecute() <<" grade";
	out << std::endl << "-------------------------------" << std::endl;
	out << std::endl;

	return (out);
}