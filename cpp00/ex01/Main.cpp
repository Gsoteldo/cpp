/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:46:44 by gabo              #+#    #+#             */
/*   Updated: 2025/04/10 01:07:15 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class/Contact.hpp"
#include "Class/PhoneBook.hpp"

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

	std::cout << std::endl << "----------------PhoneBook----------------" << std::endl;
	std::cout << "1. Add contact" << std::endl;
	std::cout << "2. Search contact" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Select an option: ";
	std::cin >> index;

	//Si falla el index, limpia lo que haya dentro de "cin" para evitar bucles infinitos
	if (std::cin.fail()) {
		if (std::cin.eof()) {
			return (-1);
		}
    	std::cin.clear();
    	std::cin.ignore(10000, '\n');
    	index = 0;
	}
	return (index);
}	

int main() {

	int index = 0;
	PhoneBook phoneBook;
	int numContacts = 0;
	while (1) {

		std::cin.clear();
		index = printMenu();
		switch (index)
		{
		case 1:
			phoneBook.addContact(numContacts);
			numContacts++;
			break;
		case 2:
			phoneBook.searchContact(numContacts);
			break;
		case 3:
			exitPhoneBook();
			return (0);
		case -1:
			std::cout << "Saliendo con Ctrl-D" << std::endl;
			return (0);
		default:
			std::cout << "Invalid option. Enter a number between 1 and 3" << std::endl;
			break;
		}
		
	}
	std::cout << std::endl;

	return (0);
}