/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:58:11 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/10/15 21:43:45 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {
		
		PresidentialPardonForm form("Top Secret");
		Bureaucrat bureaucrat("John Doe", 1);
	
		bureaucrat.signForm(form);
	
		form.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what();
		std::cerr << std::endl;
	}

	return (0);
}