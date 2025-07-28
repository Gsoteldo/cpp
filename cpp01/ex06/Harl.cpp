/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:15:03 by gabo              #+#    #+#             */
/*   Updated: 2025/07/22 20:58:23 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl << std::endl;
}

void Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years, whereas you started working here just last month.";
	std::cout << std::endl << std::endl;

}

void Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}
	


void Harl::complain(std::string level) {
	
	if (level.empty()) {
		std::cerr << "Error: Level cannot be empty." << std::endl;
		return;
	}
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	if (level != "DEBUG" && level != "INFO" && 
	    level != "WARNING" && level != "ERROR") {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	
	for (int i = 0; i < 4; i++) {

		if (level == levels[i]) {
			switch (i)
			{
				case 0:
					(this->*functions[0])();
					// fall through
				case 1:
					(this->*functions[1])();
					// fall through
				case 2:
					(this->*functions[2])();
					// fall through
				case 3:
					(this->*functions[3])();
					break;
			
				default:
					break;
			}
		}
	}
}
