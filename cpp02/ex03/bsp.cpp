/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:47:03 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/07/29 17:12:20 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(const Point p1, const Point p2, const Point p3 ) {

	Fixed area((p1.getX() * (p2.getY() - p3.getY() ) + p2.getX() * (p3.getY() - p1.getY()) \
		+ p3.getX() * (p1.getY() - p2.getY()) ) / 2 );

	if (area < 0)
		area = area * (-1);
		

	return (area);	
	
}


bool bsp( const Point &a, const Point &b, const Point &c, const Point &point) {
	Fixed areaABC = area(a, b, c);
	Fixed areaABP = area(a, b, point);
	Fixed areaACP = area(a, c, point);
	Fixed areaBCP = area(b, c, point);

	if (areaABC == 0 || areaABP == 0 || areaACP == 0 || areaBCP == 0) {
		std::cerr << "Point on a vertex or on an edge" << std::endl;
		return (false);
	}


	
	if (areaABC == (areaABP + areaACP + areaBCP)) {
		std::cout << "Point is inside the triangle" << std::endl;
		return (true);
	}
	else {
		std::cout << "Point outside the triangle" << std::endl;
		return (false);
	}
	
	
}

	// std::cout << "AreaABC " << areaABC << std::endl;
	// std::cout << "AreaABP " << areaABP << std::endl;
	// std::cout << "AreaACP " << areaACP << std::endl;
	// std::cout << "AreaBCP " << areaBCP << std::endl;