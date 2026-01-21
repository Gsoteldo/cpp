/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:44:35 by gabo              #+#    #+#             */
/*   Updated: 2026/01/21 20:33:37 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():  _name("Unnamed Form"), _isSigned(false), _toSign(150), _toExecute(150) {}

AForm::AForm(std::string name, int toSign, int toExecute): _name(name), _isSigned(false), _toSign(toSign), _toExecute(toExecute) {
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();

	std::cout << "Form: " << name << " was created" << std::endl;
	
}

AForm::AForm(const AForm &obj): _name(obj._name), _isSigned(obj._isSigned), _toSign(obj._toSign), _toExecute(obj._toExecute) {}

AForm &AForm::operator=(const AForm &obj){
	if (this != &obj) {
		_isSigned = obj._isSigned;
		_toSign = obj._toSign;
		_toExecute = obj._toExecute;
	}
	return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {

	return ("Grade too High");
}

const char* AForm::GradeTooLowException::what() const throw() {

	return ("Grade too Low");
}

const char* AForm::FormNotSigned::what() const throw() {
	return ("Form not signed to execute");
}

std::string	AForm::getName() const{
	return (_name);
}
bool	AForm::getIsSigned() const{
	return (_isSigned);
}

int	AForm::getToSign() const{
	return (_toSign);
}
int	AForm::getToExecute() const{
	return (_toExecute);
}

void AForm::beSigned(const Bureaucrat &bureau) {
	if (_toSign < bureau.getGrade())
		throw Bureaucrat::GradeTooLowToSigned();
	else
		_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	
	if (this->_isSigned == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->_toExecute)
		throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& out, const AForm &obj) {
	out << std::endl << "-------------------------------" << std::endl;
	out << "Form name: " << obj.getName() << std::endl;
	out << "Is Signed: " << obj.getIsSigned() << std::endl;
	out << "To signed is necessary: " << obj.getToSign() << " grade" << std::endl;
	out << "And to execute is necessary: " << obj.getToExecute() <<" grade";
	out << std::endl << "-------------------------------" << std::endl;
	out << std::endl;

	return (out);
}