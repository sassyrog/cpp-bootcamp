/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:14:51 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/07 11:25:00 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_nbOfFractBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(int const fpv) : _fixedPointValue(fpv) {
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed(float const fpv) : _fixedPointValue(fpv) {
    std::cout << "Float constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const &copy) : _fixedPointValue(copy._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return;
}

float Fixed::toFloat(void) const {
    return this->_fixedPointValue;
}
int Fixed::toInt(void) const {
    return this->_fixedPointValue;
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

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
    o << rhs.getRawBits();
    return o;
};
