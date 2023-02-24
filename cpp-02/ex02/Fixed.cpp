#include "Fixed.hpp"

/* -- Default constructor -- */

Fixed::Fixed() : _fixedValue(0) {}

/* -- Default constructor Int -- */

Fixed::Fixed(const int other) {
    this->_fixedValue = other << this->_fractionalBits;
}

/* -- Default constructor Float -- */

Fixed::Fixed(const float other) {
    this->_fixedValue = (int)(other * (1 << this->_fractionalBits) + 0.5);
}

/* -- Copy constructor by using copy assignment operator overload -- */

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

/* -- Copy assignment operator overload -- */

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->_fixedValue = other.getRawBits();
	}
	return *this;
}

/* -- Destructor -- */

Fixed::~Fixed() {}

/* -- Set -- */

void Fixed::setRawBits(int const raw) {
    this->_fixedValue = raw;
}

/* -- Get -- */

int Fixed::getRawBits(void) const {
    return this->_fixedValue;
}

/* -- toInt -- */

int Fixed::toInt(void) const {
    return this->_fixedValue >> this->_fractionalBits;
}

/* -- toFloat -- */

float Fixed::toFloat(void) const {
    return (float)this->_fixedValue / (1 << this->_fractionalBits);
}

/* -- Overload << operator -- */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    return os << fixed.toFloat();
}

/* -- Overload comparison operators -- */

bool Fixed::operator>(const Fixed &other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->getRawBits() != other.getRawBits();
}

/* -- Overload arithmetic operators -- */

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

/* -- Overload increment and decrement operators -- */

Fixed Fixed::operator++() {
    ++this->_fixedValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedValue++;
    return temp;
}

Fixed Fixed::operator--() {
    --this->_fixedValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedValue--;
    return temp;
}

/* -- Max and Min -- */

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
