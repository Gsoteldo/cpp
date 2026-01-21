#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(150) {
	
	std::cout << "A new bureaucrat was born and his/her name is ";
	std::cout << _name << std::endl;
}


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

const char* Bureaucrat::GradeTooLowToSigned::what() const throw() {
	
	return ("Bureaucrat Grade too Low to sign form");
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

void Bureaucrat::signForm(AForm &form) {
    if (form.getIsSigned() == true) {
        std::cout << "Form: " << form.getName() << " is already signed" << std::endl;
        return;
    }
    
    form.beSigned(*this); // Deja que lance la excepción si falla
    std::cout << _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const {
	form.execute(*this);
}

std::ostream&  operator<<(std::ostream& out, const Bureaucrat &obj) {

		out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
		out << "." << std::endl;

		return (out);
	}