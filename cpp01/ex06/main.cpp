/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:35 by gabo              #+#    #+#             */
/*   Updated: 2025/07/18 15:16:55 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}
	
	Harl harl;
	std::string level = argv[1];
	
	harl.complain(level);
	return (0);
}