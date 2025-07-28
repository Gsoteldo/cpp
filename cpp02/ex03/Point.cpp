/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:02:46 by gabo              #+#    #+#             */
/*   Updated: 2025/07/28 16:04:54 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y) {}

Point::Point(const Point &point): _x(point._x), _y(point._y) {}

Point& Point::operator=(const Point &point) {
	if (this != &point)
		return (*this);
	return (*this);
}
Point::~Point() {}

const Fixed& Point::getX() const {
	return (_x);
}

const Fixed& Point::getY() const {
	return (_y);
}

std::ostream& operator<<(std::ostream& out, const Point &point) {
	out << "_x: " << point.getX() << "_y: " << point.getY() << std::endl;

	return (out);
}