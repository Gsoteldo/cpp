/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:58:11 by gsoteldo          #+#    #+#             */
/*   Updated: 2026/01/21 20:50:45 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	srand(time(NULL));
	// PresidentialPardonForm test
	{
		try {
			PresidentialPardonForm form("Home");
			Bureaucrat bureaucrat("John Doe", 1);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 1: RobotomyRequestForm signed and executed successfully
	{
		std::cout << "\n========== TEST 1: RobotomyRequestForm signed and executed successfully ==========" << std::endl;
		try {
			RobotomyRequestForm form("House");
			Bureaucrat boss("Boss", 40); // Sufficient to sign and execute
			boss.signForm(form);
			for (int i = 0; i < 5; ++i) {
				form.execute(boss);
			}
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 2: Try to execute without signing
	{
		std::cout << "\n========== TEST 2: Execute RobotomyRequestForm without signing ==========" << std::endl;
		try {
			RobotomyRequestForm form("Car");
			Bureaucrat boss("Boss", 40);
			// Not signed
			form.execute(boss);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 3: Bureaucrat with insufficient grade to execute
	{
		std::cout << "\n========== TEST 3: Bureaucrat with insufficient grade to execute ==========" << std::endl;
		try {
			RobotomyRequestForm form("Office");
			Bureaucrat boss("Boss", 40);
			boss.signForm(form);
			Bureaucrat rookie("Rookie", 100); // Not enough to execute
			form.execute(rookie);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 4: Bureaucrat with exact grade to sign and execute
	{
		std::cout << "\n========== TEST 4: Bureaucrat with exact required grade ==========" << std::endl;
		try {
			RobotomyRequestForm form("Lab");
			Bureaucrat exact("Exact", 72); // Exactly to sign
			exact.signForm(form);
			Bureaucrat executor("Executor", 45); // Exactly to execute
			form.execute(executor);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 5: Try to sign with insufficient grade
	{
		std::cout << "\n========== TEST 5: Try to sign with insufficient grade ==========" << std::endl;
		try {
			RobotomyRequestForm form("Car");
			Bureaucrat rookie("Rookie", 100); // Not enough to sign
			rookie.signForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// SHRUBBERY TESTS

	// TEST 6: ShrubberyCreationForm signed and executed successfully
	{
		std::cout << "\n========== TEST 6: ShrubberyCreationForm signed and executed successfully ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Garden");
			Bureaucrat gardener("Gardener", 100); // Sufficient to sign and execute
			gardener.signForm(form);
			form.execute(gardener);
			std::cout << "Check file: Garden_shrubbery for ASCII trees." << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 7: Try to execute ShrubberyCreationForm without signing
	{
		std::cout << "\n========== TEST 7: Execute ShrubberyCreationForm without signing ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Park");
			Bureaucrat gardener("Gardener", 100);
			// Not signed
			form.execute(gardener);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 8: Bureaucrat with insufficient grade to execute ShrubberyCreationForm
	{
		std::cout << "\n========== TEST 8: Bureaucrat with insufficient grade to execute ShrubberyCreationForm ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Yard");
			Bureaucrat gardener("Gardener", 100);
			gardener.signForm(form);
			Bureaucrat intern("Intern", 150); // Not enough to execute
			form.execute(intern);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 9: Bureaucrat with exact grade to sign and execute ShrubberyCreationForm
	{
		std::cout << "\n========== TEST 9: Bureaucrat with exact required grade for ShrubberyCreationForm ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Forest");
			Bureaucrat exact("Exact", 145); // Exactly to sign
			exact.signForm(form);
			Bureaucrat executor("Executor", 137); // Exactly to execute
			form.execute(executor);
			std::cout << "Check file: Forest_shrubbery for ASCII trees." << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 10: Try to sign ShrubberyCreationForm with insufficient grade
	{
		std::cout << "\n========== TEST 10: Try to sign ShrubberyCreationForm with insufficient grade ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Street");
			Bureaucrat intern("Intern", 150); // Not enough to sign
			intern.signForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	// TEST 11: Bureaucrat::executeForm with successful execution
	{
		std::cout << "\n========== TEST 11: Bureaucrat::executeForm with successful execution ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Balcony");
			Bureaucrat gardener("Gardener", 100);
			gardener.signForm(form);
			gardener.executeForm(form);
			std::cout << "Check file: Balcony_shrubbery for ASCII trees." << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 12: Bureaucrat::executeForm with unsigned form
	{
		std::cout << "\n========== TEST 12: Bureaucrat::executeForm with unsigned form ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Roof");
			Bureaucrat gardener("Gardener", 100);
			gardener.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	// TEST 13: Bureaucrat::executeForm with insufficient grade
	{
		std::cout << "\n========== TEST 13: Bureaucrat::executeForm with insufficient grade ==========" << std::endl;
		try {
			ShrubberyCreationForm form("Patio");
			Bureaucrat gardener("Gardener", 100);
			gardener.signForm(form);
			Bureaucrat intern("Intern", 150);
			intern.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}