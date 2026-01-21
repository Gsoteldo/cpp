/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:44:54 by gabo              #+#    #+#             */
/*   Updated: 2026/01/21 20:35:19 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
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
		class FormNotSigned: public std::exception {
			public:
			virtual const char* what() const throw();
		};
	
		AForm();
		AForm(std::string name, int toSign, int toExecute);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int 		getToSign() const;
		int			getToExecute() const;

		

		void		beSigned(const Bureaucrat &bureau);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

	std::ostream& operator<<(std::ostream& out, const AForm &obj);

#endif