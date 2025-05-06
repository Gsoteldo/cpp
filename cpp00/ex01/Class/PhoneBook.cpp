/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:46:50 by gabo              #+#    #+#             */
/*   Updated: 2025/05/06 21:28:58 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

int PhoneBook::inputData(std::string inputType, int numContacts) {
	
	std::string input;
	
	do
	{
		// std::cin.ignore(10000, '\n');
		if (inputType == "dark secret")
			std::cout << "Introduce your " << inputType << "(We won't tell anyone :) ):";
		else
			std::cout << "Introduce your " << inputType << ": ";
		std::getline(std::cin, input);
		if (input.empty()) {
			if (std::cin.eof()) {
				std::cout << "Ctrl-D detected. Exiting..." << std::endl;
				return (0);
			}
			std::cout << inputType << " cannot be empty. Please try again.";
			std::cout << std::endl << std::endl;
		}
	} while (input.empty());
	
	if (inputType == "first name")
		_contact[numContacts % 8].setFirstName(input);
	else if (inputType == "last name")
		_contact[numContacts % 8].setLastName(input);
	else if (inputType == "nickname")
		_contact[numContacts % 8].setNickname(input);
	else if (inputType == "phone number")
		_contact[numContacts % 8].setPhoneNumber(input);
	else if (inputType == "dark secret")
		_contact[numContacts % 8].setDarkSecret(input);
	else
		std::cout << "Invalid input type" << std::endl << std::endl;
	std::cout << std::endl;
	return (1);
}

int PhoneBook::addContact(int numContacts) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkSecret;
	std::string	phoneNumber;

	if (inputData("first name", numContacts) == 0)
		return (0);
	if (inputData("last name", numContacts) == 0)
		return (0);
	if (inputData("nickname", numContacts) == 0)
		return (0);
	if (inputData("phone number", numContacts) == 0)
		return (0);
	if (inputData("dark secret", numContacts) == 0)
		return (0);
	



 	// std::cout << "Introduce your last name: ";
	// std::cin >> lastName;
	// _contact[numContacts % 8].setLastName(lastName);
	// std::cin.clear();

	// std::cout << "Introduce your nickname: ";
	// std::cin >> nickName;
	// _contact[numContacts % 8].setNickname(nickName);
	// std::cin.clear();

	// std::cout << "Introduce your phoneNumber: ";
	// std::cin >> phoneNumber;
	// _contact[numContacts % 8].setPhoneNumber(phoneNumber);
	// std::cin.clear();

	// std::cout << "Introduce your dark secrets (We won't tell anyone :) ): ";

	// // Limpia el buffer de entrada para evitar problemas con getline
	// std::cin.ignore(10000, '\n');

	// // Lee la cadena de caracteres de std::cin hasta el final de la linea
	// // y lo guarda en darkSecret.
	// std::getline(std::cin ,darkSecret);
	// _contact[numContacts % 8].setDarkSecret(darkSecret);
	// std::cin.clear();

	return (1);
}

std::string PhoneBook::formatField(std::string field) {
    if (field.length() > 10)
        return field.substr(0, 9) + "."; // Deja solo 9 caracteres de la cadena y añade un punto
    else
        return std::string(10 - field.length(), ' ') + field; // rellena con espacios delante de la cadena
}

void PhoneBook::filterContact() {

	int index = 0;
	std::cout << "Filter one user by their ID: ";
	std::cin >> index;

	if (index >= 0 && index < 8) {
		std::cout << std::endl  << "------------------------" << std::endl;
		std::cout << "User ID: " << index << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "-> First Name: " << _contact[index].getFirstName() << std::endl; 
		std::cout << "-> Last Name: " << _contact[index].getLastName() << std::endl; 
		std::cout << "-> Nickname: " << _contact[index].getNickname() << std::endl; 
		std::cout << "-> Phone Number: "<< _contact[index].getPhoneNumber() << std::endl; 
		std::cout << "-> Darkest secret: "<< _contact[index].getDarkSecret() << std::endl; 
	} else {
		std::cout << "Invalid Id" << std::endl;
	}
	std::cin.ignore(10000, '\n');
}

void PhoneBook::searchContact(int numContacts) {

	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	if (numContacts < 8) {
		for (int i = 0; i < numContacts; i++)
		{
    		std::cout << "--------------------------------------------------" << std::endl;
			std::cout << " " << std::setw(10) << i << "|"; //Ajusta el tamano de la columna
			std::cout << std::setw(10) << formatField(_contact[i].getFirstName()) << "|";
			std::cout << std::setw(10) << formatField(_contact[i].getLastName()) << "|";
			std::cout << std::setw(10) << formatField(_contact[i].getNickname()) << "|" << std::endl;
		}
		std::cout << "--------------------------------------------------" << std::endl << std::endl;
		filterContact();
		
	} else {
		for (size_t i = 0; i < 8; i++)
		{
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << " " << std::setw(10) << i << "|"; //Ajusta el tamano de la columna
			std::cout << std::setw(10) << formatField(_contact[i].getFirstName()) << "|";
			std::cout << std::setw(10) << formatField(_contact[i].getLastName()) << "|";
			std::cout << std::setw(10) << formatField(_contact[i].getNickname()) << "|" << std::endl;
		}
		std::cout << "--------------------------------------------------" << std::endl << std::endl;
		filterContact();
	}
}