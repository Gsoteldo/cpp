/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:44:54 by gabo              #+#    #+#             */
/*   Updated: 2025/10/09 19:44:18 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_isSigned;
		int					_toSign;
		int					_toExecute;
		
	public:

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
	
		Form();
		Form(std::string name, int toSign, int toExecute);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();

		std::string	getName() const;
		bool		getIsSigned() const;
		int 		getToSign() const;
		int			getToExecute() const;

		

		void		beSigned(const Bureaucrat &bureau);
		

};

	std::ostream& operator<<(std::ostream& out, const Form &obj);

#endif