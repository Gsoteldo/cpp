/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:44:07 by gabo              #+#    #+#             */
/*   Updated: 2025/07/28 12:10:47 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
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