/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:58:11 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/10/06 20:38:33 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

	try {
		int a = 2, b = 0;

		if (b == 0)
			throw 0;
		int c = a / b;

		std::cout << "La division es: " << c << std::endl;
	} catch (const) {
		std::cerr << "Excepcion: " << e << std::endl;
	}

	return (0);
}