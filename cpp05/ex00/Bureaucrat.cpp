#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(150) {}


Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {

	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}

	std::cout << "A new bureaucrat was born and his/her name is ";
	std::cout << name << std::endl;

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj._name), _grade(obj._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj) {
		_grade = obj._grade;
	}
	return (*this);
}


std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

/*
	Las excepciones deben heredar de std::exception y sobreescribir el método what()
	para que devuelva un mensaje de error adecuado.


*/
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	
	return ("Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	
	return ("Grade too Low");
}

void Bureaucrat::increaseGrade() {
	_grade--;
	if (_grade < 1) 
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade() {
	_grade++;
	if (_grade > 150) 
		throw GradeTooLowException();
}


std::ostream&  operator<<(std::ostream& out, const Bureaucrat &obj) {

		out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
		out << "." << std::endl;

		return (out);
	}