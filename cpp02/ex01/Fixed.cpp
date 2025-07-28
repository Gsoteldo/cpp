/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:44:07 by gabo              #+#    #+#             */
/*   Updated: 2025/07/28 14:58:09 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	_fixedPointValue = num * (1 << _fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) {
	_fixedPointValue = roundf(num * (1 << _fractionalBits));

}

Fixed::Fixed(const Fixed &fixed) {
	_fixedPointValue = fixed._fixedPointValue;
	std::cout << "Copy constructor called" << std::endl;
	// 
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed)
		this->_fixedPointValue = fixed._fixedPointValue;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}



Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return(_fixedPointValue);
}

void Fixed::setRawBits( int const raw ){
	_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
	float result;
	
	result = static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);

	return (result);
}

int Fixed::toInt( void ) const {
	int result;

	result = _fixedPointValue >> _fractionalBits;

	return (result);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();

	return (out);
}

