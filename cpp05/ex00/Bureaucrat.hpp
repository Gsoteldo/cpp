/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:32:24 by gabo              #+#    #+#             */
/*   Updated: 2025/10/08 13:05:56 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		std::string	_name;
		int					_grade;
	public:

		//La excepcion debe estar en una clase anidada
		// dentro de Bureaucrat
		// y debe heredar de std::exception
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		
		std::string getName() const;
		int getGrade() const;

		void increaseGrade();
		void decreaseGrade();
		
		
	};
	std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);

#endif