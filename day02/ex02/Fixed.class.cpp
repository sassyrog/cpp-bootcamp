/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:14:51 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/07 13:29:48 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_nbOfFractBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(int const fpv) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = fpv << this->_nbOfFractBits;
    return;
}

Fixed::Fixed(float const fpv) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(fpv * (1 << this->_nbOfFractBits));
    return;
}

Fixed::Fixed(Fixed const &copy) : _fixedPointValue(copy._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << this->_nbOfFractBits);
}
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_nbOfFractBits;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
    return;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return;
}

bool Fixed::operator<(Fixed const &rhs) const {
    if (this->_fixedPointValue < rhs.getRawBits())
        return true;
    return false;
}
bool Fixed::operator>(Fixed const &rhs) const {
    if (this->_fixedPointValue > rhs.getRawBits())
        return true;
    return false;
}
bool Fixed::operator>=(Fixed const &rhs) const {
    if (this->_fixedPointValue >= rhs.getRawBits())
        return true;
    return false;
}
bool Fixed::operator<=(Fixed const &rhs) const {
    if (this->_fixedPointValue <= rhs.getRawBits())
        return true;
    return false;
}
bool Fixed::operator==(Fixed const &rhs) const {
    if (this->_fixedPointValue == rhs.getRawBits())
        return true;
    return false;
}
bool Fixed::operator!=(Fixed const &rhs) const {
    if (this->_fixedPointValue != rhs.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    return (Fixed(this->_fixedPointValue + rhs.getRawBits()));
}
Fixed Fixed::operator-(Fixed const &rhs) const {
    return (Fixed(this->_fixedPointValue - rhs.getRawBits()));
}
Fixed Fixed::operator*(Fixed const &rhs) const {
    return (Fixed(this->_fixedPointValue * rhs.getRawBits()));
}
Fixed Fixed::operator/(Fixed const &rhs) const {
    if (rhs.getRawBits() == 0) {
        std::cout << "Can't" << std::endl;
        return;
    }
    return (Fixed(this->_fixedPointValue / rhs.getRawBits()));
}
Fixed &Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->operator++();
    return (tmp);
}

Fixed &Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->operator--();
    return (tmp);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return o;
};
