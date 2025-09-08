#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		
	public:

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		
};