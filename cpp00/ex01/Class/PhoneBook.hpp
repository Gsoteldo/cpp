/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:59:51 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/05/06 21:28:57 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {

	private:
		Contact _contact[8];

		std::string formatField(std::string field);
		void filterContact();
		int inputData(std::string inputType, int numContacts);
	public:
		PhoneBook();
		~PhoneBook();

		/****************************FUNCTIONS****************************/
		int addContact(int numContacts);
		void searchContact(int numContacts);	
};

#endif