/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:44:07 by gabo              #+#    #+#             */
/*   Updated: 2025/07/29 17:04:26 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) {
}

Fixed::Fixed(const int num) {
	_fixedPointValue = num * (1 << _fractionalBits);
}

Fixed::Fixed(const float num) {
	_fixedPointValue = roundf(num * (1 << _fractionalBits));

}

Fixed::Fixed(const Fixed &fixed) {
	_fixedPointValue = fixed._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed)
		this->_fixedPointValue = fixed._fixedPointValue;
	return (*this);
}



Fixed::~Fixed() {}


int Fixed::getRawBits(void) const {
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

/* Comparison operators */
bool Fixed::operator>(const Fixed &fixed) const{
	return (getRawBits() > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (getRawBits() >= fixed.getRawBits());
}
bool Fixed::operator<(const Fixed &fixed) const {
	return (getRawBits() < fixed.getRawBits());
}
bool Fixed::operator<=(const Fixed &fixed) const {
	return (getRawBits() <= fixed.getRawBits());
}
bool Fixed::operator==(const Fixed &fixed) const {
	return (getRawBits() == fixed.getRawBits());
}
bool Fixed::operator!=(const Fixed &fixed) const{
	return (getRawBits() != fixed.getRawBits());
}

/* Arithmetic operators */
Fixed Fixed::operator+(const Fixed &fixed) const {
	return (Fixed(toFloat() + fixed.toFloat()));
}
Fixed Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(toFloat() - fixed.toFloat()));
}
Fixed Fixed::operator*(const Fixed &fixed) const {
	return (Fixed(toFloat() * fixed.toFloat()));
}
Fixed Fixed::operator/(const Fixed &fixed) const {
	return (Fixed(toFloat() / fixed.toFloat()));
}

/* Increment/Decrement operators */
Fixed& Fixed::operator++() {
	++(_fixedPointValue);
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed oldValue(*this);
	++(_fixedPointValue);
	return (oldValue);
}
Fixed& Fixed::operator--() {
	--(_fixedPointValue);
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed oldValue(*this);
	--(_fixedPointValue);
	return (oldValue);
}


Fixed& Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

