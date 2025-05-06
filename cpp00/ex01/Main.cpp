/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:46:44 by gabo              #+#    #+#             */
/*   Updated: 2025/05/06 21:24:22 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class/Contact.hpp"
#include "Class/PhoneBook.hpp"

// void	exitPhoneBook(){
// 	std::cout << "Sale de la agenda" << std::endl;
// }

// void	searchContact() {
// 	std::cout << "Entra en la funcion de buscar" << std::endl;
// }

// void	addContact() {
// 	std::cout << "Entra en la funcion de añadir" << std::endl;
// }

std::string	printMenu() {

	std::string index;

	std::cout << std::endl << "----------------PhoneBook----------------" << std::endl;
	std::cout << "ADD: Add contact" << std::endl;
	std::cout << "SEARCH: Search contact" << std::endl;
	std::cout << "EXIT: Exit" << std::endl;
	std::cout << "Please, select an option: ";
	std::getline(std::cin, index);

	//Si falla el index, limpia lo que haya dentro de "cin" para evitar bucles infinitos
	if (std::cin.fail()) {
		if (std::cin.eof()) {
			return ("Ctrl-D");
		}
    	// std::cin.clear();
    	// std::cin.ignore(10000, '\n');
    	index = "Invalid";
	}
	return (index);
}	

int main() {

	std::string index;
	PhoneBook phoneBook;
	int numContacts = 0;
	while (1) {

		// std::cin.clear();
		index = printMenu();
		if (index == "ADD") {
			if (phoneBook.addContact(numContacts) == 0)
			{
				std::cout << "Exiting PhoneBook..." << std::endl;
				break;
			}
			
			numContacts++;
		}
		else if (index == "SEARCH") {
			phoneBook.searchContact(numContacts);
		}
		else if (index == "EXIT") {
			std::cout << "Exiting PhoneBook..." << std::endl;
			break;
		}
		else if (index == "Ctrl-D") {
			std::cout << std::endl << "Exiting with Ctrl-D" << std::endl;
			break;
		}
		else {
			std::cout << "Invalid option. Enter a number between 1 and 3" << std::endl;
		}		
	}
	std::cout << std::endl;

	return (0);
}