/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:58:11 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/10/08 13:01:20 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {

	std::cout << "========== TEST 1: Grade too high (0) ==========" << std::endl;
	try {
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 2: Grade too low (151) ==========" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 3: Valid grade (75) ==========" << std::endl;
	try {
		Bureaucrat alice("Alice", 75);
		std::cout << alice << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 4: Minimum valid grade (1) ==========" << std::endl;
	try {
		Bureaucrat dave("Dave", 1);
		std::cout << dave << std::endl;
		
		std::cout << "Trying to increase grade..." << std::endl;
		dave.increaseGrade(); // Esto debería lanzar excepción
		std::cout << dave << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 5: Maximum valid grade (150) ==========" << std::endl;
	try {
		Bureaucrat eve("Eve", 150);
		std::cout << eve << std::endl;
		
		std::cout << "Trying to decrease grade..." << std::endl;
		eve.decreaseGrade(); // Esto debería lanzar excepción
		std::cout << eve << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 6: Increase grade successfully ==========" << std::endl;
	try {
		Bureaucrat frank("Frank", 50);
		std::cout << frank << std::endl;
		
		frank.increaseGrade();
		std::cout << "After increasing grade: " << frank << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 7: Decrease grade successfully ==========" << std::endl;
	try {
		Bureaucrat grace("Grace", 100);
		std::cout << grace << std::endl;
		
		grace.decreaseGrade();
		std::cout << "After decreasing grade: " << grace << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}