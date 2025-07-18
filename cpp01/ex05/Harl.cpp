/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:15:03 by gabo              #+#    #+#             */
/*   Updated: 2025/07/18 14:03:27 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years, whereas you started working here just last month.";
	std::cout << std::endl;

}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
	


void Harl::complain(std::string level) {
	
	if (level.empty()) {
		std::cerr << "Error: Level cannot be empty." << std::endl;
		return;
	}
	if (level != "DEBUG" && level != "INFO" && 
	    level != "WARNING" && level != "ERROR") {
		std::cerr << "Error: Invalid level. Valid levels are: DEBUG, INFO, WARNING, ERROR." << std::endl;
		return;
	}
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*functions[i])();
			return;
		}
	}
}
