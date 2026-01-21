/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:58:24 by gabo              #+#    #+#             */
/*   Updated: 2026/01/22 00:35:35 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"


class Intern {
	private:
		std::string formName[3];
		AForm *(Intern::*forms[3])(const std::string &target);
		AForm *CreateShrubberyForm(const std::string &target);
		AForm *CreateRobotomyForm(const std::string &target);
		AForm *CreatePresidentialForm(const std::string &target);
	public:
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern();

		int getIndex(const std::string &formType);

		AForm *makeForm(const std::string &formType, const std::string &target);

};

#endif