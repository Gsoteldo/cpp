/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:08:24 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/17 18:27:00 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	/*Direcciones de memoria */
	
	std::cout << "Memory address from str: " << &str << std::endl;
	std::cout << "Memory address from stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address from stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	
	/* Valores */
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Cambiando stringReF" << std::endl;

	stringREF = "Changing stringREF";

		std::cout << "Memory address from str: " << &str << std::endl;
	std::cout << "Memory address from stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address from stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	
	/* Valores */
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	
		std::cout << "Cambiando str" << std::endl;

	str = "Changing str";

		std::cout << "Memory address from str: " << &str << std::endl;
	std::cout << "Memory address from stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address from stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	
	/* Valores */
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	
		std::cout << "Cambiando stringPTR" << std::endl;

	*stringPTR = "Changing stringPTR";

		std::cout << "Memory address from str: " << &str << std::endl;
	std::cout << "Memory address from stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address from stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	
	/* Valores */
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	

	
	return (0);
}