/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:47:32 by gabo              #+#    #+#             */
/*   Updated: 2025/05/06 20:15:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkSecret;
	public:
		Contact();
		Contact(
			const std::string firstName,
			const std::string lastName,
			const std::string nickName,
			const std::string phoneNumber,
			const std::string darkSecret);
		~Contact();


		/* ****************************GETTERS*****************************/
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkSecret() const;
		/*****************************SETTERS*****************************/
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkSecret(std::string darkSecret);


		/****************************FUNCTIONS****************************/
		void		presentation() const;
};


#endif