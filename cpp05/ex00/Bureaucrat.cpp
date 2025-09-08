#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {

}

Bureaucrat::~Bureaucrat() {

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too High");
}