/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:46:44 by gabo              #+#    #+#             */
/*   Updated: 2025/04/08 21:08:16 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class/Contact.hpp"

void	exitPhoneBook(){
	std::cout << "Sale de la agenda" << std::endl;
}

void	searchContact() {
	std::cout << "Entra en la funcion de buscar" << std::endl;
}

void	addContact() {
	std::cout << "Entra en la funcion de añadir" << std::endl;
}

int	printMenu() {

	int index = 0;

	std::cout << "----------------PhoneBook----------------" << std::endl;
	std::cout << "1. Add contact" << std::endl;
	std::cout << "2. Search contact" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Select an option: ";
	std::cin >> index;
	if (std::cin.fail()) {
    	std::cin.clear();
    	std::cin.ignore(10000, '\n');
    	index = 0;
	}
	return (index);
}	

int main() {

	int index = 0;

	// index = printMenu();
	Contact ejemplo;
	// std::cin >> index;
	while (index != 3) {

		std::cin.clear();
		index = printMenu();
		std::cout << "el numero seleccionado fue el " << index << std::endl;
		switch (index)
		{
		case 1:
			addContact();
			break;
		case 2:
			searchContact();
			break;
		case 3:
			exitPhoneBook();
			return 0;
		default:
			std::cout << "Introduce un numero entre 1 y 3" << std::endl;
			break;
		
		}
	}
	std::cout << std::endl;

	return (0);
}