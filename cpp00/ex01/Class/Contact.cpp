/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:47:08 by gabo              #+#    #+#             */
/*   Updated: 2025/08/10 19:05:08 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Contact::Contact() {
// 	_firstName = "Anonimo";
// 	_lastName = "Anonimo";
// 	_nickname = "An";
// 	_darkSecret = "Anomimo";
// 	_phoneNumber = 000000000;
// }

/*

class persona {

	private:
		std::string name;

	public:

};














*/











Contact::Contact() {}

Contact::Contact(
	const std::string firstName,
	const std::string lastName,
	const std::string nickName,
	const std::string phoneNumber,
	const std::string darkSecret
)
	: _firstName(firstName),
	_lastName(lastName),
	_nickname(nickName),
	_phoneNumber(phoneNumber),
	_darkSecret(darkSecret) {}

Contact::~Contact() {}

void Contact::presentation() const {
	std::cout << "Hola soy " << _firstName << " " << _lastName << " " << " este es mi numero: " << _phoneNumber << std::endl;
}

/* ****************************GETTERS*****************************/
std::string Contact::getFirstName() const {
	return (_firstName);
}

std::string Contact::getLastName() const {
	return (_lastName);
}

std::string Contact::getNickname() const {
	return (_nickname);
}

std::string Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string Contact::getDarkSecret() const {
	return (_darkSecret);
}

/* ****************************SETTERS*****************************/
void Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkSecret(std::string darkSecret) {
	_darkSecret = darkSecret;
}



