/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:46:50 by gabo              #+#    #+#             */
/*   Updated: 2025/04/10 00:00:34 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(int numContacts) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkSecret;
	std::string	phoneNumber;


	std::cout << (numContacts % 8)<< "Introduce your first name: ";
	std::cin >> firstName;
	_contact[numContacts % 8].setFirstName(firstName);
	std::cin.clear();

 	std::cout << "Introduce your last name: ";
	std::cin >> lastName;
	_contact[numContacts % 8].setLastName(lastName);
	std::cin.clear();

	std::cout << "Introduce your nickname: ";
	std::cin >> nickName;
	_contact[numContacts % 8].setNickname(nickName);
	std::cin.clear();

	std::cout << "Introduce your phoneNumber: ";
	std::cin >> phoneNumber;
	_contact[numContacts % 8].setPhoneNumber(phoneNumber);
	std::cin.clear();

	std::cout << "Introduce your dark secrets (We won't tell anyone :) ): ";
	std::cin >> darkSecret;
	_contact[numContacts % 8].setDarkSecret(darkSecret);
	std::cin.clear();
}

std::string PhoneBook::formatField(std::string field) {
    if (field.length() > 10)
        return field.substr(0, 9) + "."; // 9 letras + "." = 10 caracteres
    else
        return std::string(10 - field.length(), ' ') + field; // rellena con espacios delante
}

void PhoneBook::filterContact(int numContacts) {

	int index = 0;
	std::cout << "Filter one user by their ID: ";
	std::cin >> index;

	if (index >= 0 && index <= numContacts) {
		std::cout << "User id: " << index << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "First Name: " << _contact[index].getFirstName() << std::endl; 
		std::cout << "Last Name: " << _contact[index].getLastName() << std::endl; 
		std::cout << "Nickname: " << _contact[index].getNickname() << std::endl; 
		std::cout << "Phone Number: "<< _contact[index].getPhoneNumber() << std::endl; 
		std::cout << "Darkest secret: "<< _contact[index].getDarkSecret() << std::endl; 
	} else {
		std::cout << "Invalid Id" << std::endl;
	}
	
}

void PhoneBook::searchContact(int numContacts) {

	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	if (numContacts < 8) {
		for (int i = 0; i < numContacts; i++)
		{
    		std::cout << "--------------------------------------------------" << std::endl;
			std::cout << " " << std::setw(10) << i << "|";
			std::cout << formatField(_contact[i].getFirstName()) << "|";
			std::cout << formatField(_contact[i].getLastName()) << "|";
			std::cout << formatField(_contact[i].getNickname()) << "|" << std::endl;
		}
		std::cout << "--------------------------------------------------" << std::endl << std::endl;
		filterContact(numContacts);
		
	} else {
		for (size_t i = 0; i < 8; i++)
		{
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << " " << std::setw(10) << i << "|";
			std::cout << formatField(_contact[i].getFirstName()) << "|";
			std::cout << formatField(_contact[i].getLastName()) << "|";
			std::cout << formatField(_contact[i].getNickname()) << "|" << std::endl;
		}
		std::cout << "--------------------------------------------------" << std::endl << std::endl;
		filterContact(8);
	}
		

}