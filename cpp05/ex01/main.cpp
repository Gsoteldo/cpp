/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:58:11 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/10/09 17:19:35 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	/*
	 * TEST 1: Intentar crear un formulario con grado demasiado alto (0)
	 * Resultado esperado: Se debe lanzar una excepción GradeTooHighException
	 * ya que el grado mínimo válido es 1.
	 */
	{
		std::cout << "========== TEST 1: Create form with invalid grade (too high) ==========" << std::endl;
		try {
			Form form("Tax Form", 0, 50);
			std::cout << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 2: Intentar crear un formulario con grado demasiado bajo (151)
	 * Resultado esperado: Se debe lanzar una excepción GradeTooLowException
	 * ya que el grado máximo válido es 150.
	 */
	{
		std::cout << "========== TEST 2: Create form with invalid grade (too low) ==========" << std::endl;
		try {
			Form form("Contract", 50, 151);
			std::cout << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 3: Crear un formulario válido con grados dentro del rango permitido
	 * Resultado esperado: El formulario se crea correctamente sin excepciones.
	 * Se muestra la información del formulario (nombre, estado de firma, grados requeridos).
	 */
	{
		std::cout << "========== TEST 3: Create valid form ==========" << std::endl;
		try {
			Form form("Permit A38", 75, 50);
			std::cout << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 4: Burócrata con grado insuficiente intenta firmar un formulario
	 * Resultado esperado: El burócrata John (grado 150) no puede firmar un formulario
	 * que requiere grado 10. El método signForm debe imprimir un mensaje de error
	 * indicando que el burócrata no puede firmar porque su grado es demasiado bajo.
	 */
	{
		std::cout << "========== TEST 4: Bureaucrat with insufficient grade tries to sign ==========" << std::endl;
		try {
			Form form("Important Document", 10, 5);
			Bureaucrat lowRank("John", 150);
			std::cout << "Before signing:" << form << std::endl;
			
			lowRank.signForm(form);
			std::cout << "After signing:" << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 5: Burócrata con grado suficiente firma exitosamente
	 * Resultado esperado: El burócrata Alice (grado 30) puede firmar un formulario
	 * que requiere grado 50. El formulario debe cambiar su estado de _isSigned a true.
	 * Se muestra un mensaje de éxito indicando que el formulario fue firmado.
	 */
	{
		std::cout << "========== TEST 5: Bureaucrat with sufficient grade signs successfully ==========" << std::endl;
		try {
			Form form("Budget Report", 50, 25);
			Bureaucrat manager("Alice", 30);
			std::cout << "Before signing:" << form << std::endl;
			
			manager.signForm(form);
			std::cout << "After signing:" << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 6: Firmar con el grado exacto requerido (caso límite)
	 * Resultado esperado: El burócrata Bob (grado 42) puede firmar un formulario
	 * que requiere exactamente grado 42. Esto verifica que la comparación de grados
	 * es inclusiva (<=) y no exclusiva (<).
	 */
	{
		std::cout << "========== TEST 6: Sign form with exact required grade ==========" << std::endl;
		try {
			Form form("Approval Form", 42, 21);
			Bureaucrat supervisor("Bob", 42);
			std::cout << "Before signing:" << form << std::endl;
			
			supervisor.signForm(form);
			std::cout << "After signing:" << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 7: Intentar firmar un formulario ya firmado
	 * Resultado esperado: El primer burócrata (Charlie) firma exitosamente.
	 * Cuando el segundo burócrata (Dave) intenta firmar el mismo formulario,
	 * debe mostrarse un mensaje indicando que el formulario ya está firmado.
	 * El estado del formulario no debe cambiar.
	 */
	{
		std::cout << "========== TEST 7: Try to sign already signed form ==========" << std::endl;
		try {
			Form form("License", 100, 80);
			Bureaucrat officer1("Charlie", 50);
			Bureaucrat officer2("Dave", 60);
			
			std::cout << "Before any signature:" << form << std::endl;
			officer1.signForm(form);
			std::cout << "After first signature:" << form << std::endl;
			officer2.signForm(form);
			std::cout << "After second signature attempt:" << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 8: Burócrata de máximo rango firma formulario de alta seguridad
	 * Resultado esperado: El presidente (grado 1) puede firmar un formulario
	 * que requiere el grado más alto posible (1). Esto verifica que los
	 * casos extremos funcionan correctamente.
	 */
	{
		std::cout << "========== TEST 8: High-ranking bureaucrat signs high-security form ==========" << std::endl;
		try {
			Form form("Presidential Pardon", 1, 1);
			Bureaucrat president("President", 1);
			
			std::cout << "Before signing:" << form << std::endl;
			president.signForm(form);
			std::cout << "After signing:" << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 9: Burócrata con un grado justo por debajo del requerido
	 * Resultado esperado: El burócrata Eve (grado 26) NO puede firmar un formulario
	 * que requiere grado 25. Recuerda que los grados más bajos son mejores,
	 * por lo que 26 > 25, lo que significa que Eve no tiene suficiente autoridad.
	 */
	{
		std::cout << "========== TEST 9: Bureaucrat one grade too low ==========" << std::endl;
		try {
			Form form("Restricted Access", 25, 10);
			Bureaucrat worker("Eve", 26);
			
			std::cout << "Before signing:" << form << std::endl;
			worker.signForm(form);
			std::cout << "After signing:" << form << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
	 * TEST 10: Escenario complejo con múltiples formularios y burócratas
	 * Resultado esperado:
	 * - Junior (grado 100) firma Form A (requiere 100) ✓
	 * - Junior intenta firmar Form B (requiere 50) ✗ - falla
	 * - Senior (grado 50) firma Form B (requiere 50) ✓
	 * - Senior intenta firmar Form C (requiere 25) ✗ - falla
	 * - Chief (grado 25) firma Form C (requiere 25) ✓
	 * Este test verifica múltiples interacciones y diferentes niveles de autoridad.
	 */
	{
		std::cout << "========== TEST 10: Multiple forms, multiple bureaucrats ==========" << std::endl;
		try {
			Form form1("Form A", 100, 50);
			Form form2("Form B", 50, 25);
			Form form3("Form C", 25, 10);
			
			Bureaucrat junior("Junior", 100);
			Bureaucrat senior("Senior", 50);
			Bureaucrat chief("Chief", 25);
			
			junior.signForm(form1);
			junior.signForm(form2); // Should fail
			senior.signForm(form2);
			senior.signForm(form3); // Should fail
			chief.signForm(form3);
			
			std::cout << form1 << form2 << form3 << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	return (0);
}