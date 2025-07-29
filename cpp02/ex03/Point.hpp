/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:02:43 by gabo              #+#    #+#             */
/*   Updated: 2025/07/29 17:12:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &point);
		Point& operator=(const Point &point);
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;
};

	std::ostream& operator<<(std::ostream &out, const Point &point);
	bool bsp( const Point &a, const Point &b, const Point &c, const Point &point);
#endif