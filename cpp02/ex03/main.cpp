/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:44:10 by gabo              #+#    #+#             */
/*   Updated: 2025/07/28 21:25:17 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {

	/* Test, inside the triangle*/
	{
		
	Point a( 1, 1 );
	Point b( 4, 2 );
	Point c( 3, 5 );
	Point p( 3, 3 );
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	bsp(a,b,c,p);
	}

	/* Test, outside the triangle*/
	{
		
	Point a( 1, 1 );
	Point b( 4, 2 );
	Point c( 3, 5 );
	Point p( 3, 10 );
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	bsp(a,b,c,p);
	}


	/* Test ok, in a vertex*/
	{
		
	Point a( 1, 1 );
	Point b( 4, 2 );
	Point c( 3, 5 );
	Point p( 3, 5 );
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	bsp(a,b,c,p);
	
	}
	return 0;
}