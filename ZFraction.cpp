#include "ZFraction.h"

//Constructeur

ZFraction::ZFraction(int numerator, int denominator) : 
	m_numerator(numerator), m_denominator(denominator)
{
	this->minimize();
}

//Méthodes

void ZFraction::print(std::ostream& stream) {
	stream << m_numerator << "/" << m_denominator;
}

bool ZFraction::isEqual(ZFraction const& other) const {
	return m_numerator == other.m_numerator && m_denominator == other.m_denominator;
}

bool ZFraction::isLt(ZFraction const& other) const {
	int a(m_numerator * other.m_denominator);
	int b(other.m_numerator * m_denominator);


	return a < b;
}

void ZFraction::minimize() {
	int t = pgcd(m_numerator, m_denominator);
	m_numerator /= t;
	m_denominator /= t;

	if (m_denominator < 0) {
		m_numerator *= -1;
		m_denominator *= -1;
	}
}

//Entre fractions
ZFraction& ZFraction::operator+=(ZFraction const& other) {
	int a(m_numerator * other.m_denominator);
	int b(other.m_numerator * m_denominator);
	int c(m_denominator * other.m_denominator);

	m_numerator = a + b;
	m_denominator = c;

	this->minimize();
	return *this;
}
ZFraction& ZFraction::operator-=(ZFraction const& other) {
	int a(m_numerator * other.m_denominator);
	int b(other.m_numerator * m_denominator);
	int c(m_denominator * other.m_denominator);

	m_numerator = a - b;
	m_denominator = c;

	this->minimize();
	return *this;
}
ZFraction& ZFraction::operator*=(ZFraction const& other) {
	m_numerator *= other.m_numerator;
	m_denominator *= other.m_denominator;

	this->minimize();
	return *this;
}
ZFraction& ZFraction::operator/=(ZFraction const& other) {
	m_numerator *= other.m_denominator;
	m_denominator *= other.m_numerator;

	this->minimize();
	return *this;
}

//Fraction et int
ZFraction& ZFraction::operator+=(int const& other) {
	*this += ZFraction(other);
	return *this;
}
ZFraction& ZFraction::operator-=(int const& other) {
	*this -= ZFraction(other);
	return *this;
}
ZFraction& ZFraction::operator*=(int const& other) {
	*this *= ZFraction(other);
	return *this;
}
ZFraction& ZFraction::operator/=(int const& other) {
	*this /= ZFraction(other);
	return *this;
}

//Fonctions
int pgcd(int a, int b) {
	while (b != 0)
	{
		const int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

bool operator==(ZFraction const& a, ZFraction const& b) {
	return a.isEqual(b);
}
bool operator!=(ZFraction const& a, ZFraction const& b) {
	return !(a == b);
}
bool operator<(ZFraction const& a, ZFraction const& b) {
	return a.isLt(b);
}
bool operator<=(ZFraction const& a, ZFraction const& b) {
	return a < b || a == b;
}
bool operator>(ZFraction const& a, ZFraction const& b) {
	return !(a <= b);
}
bool operator>=(ZFraction const& a, ZFraction const& b) {
	return !(a < b);
}

ZFraction operator+(ZFraction const& a, ZFraction const& b) {
	ZFraction result(a);
	return result += b;
}
ZFraction operator-(ZFraction const& a, ZFraction const& b) {
	ZFraction result(a);
	return result -= b;
}
ZFraction operator*(ZFraction const& a, ZFraction const& b) {
	ZFraction result(a);
	return result *= b;
}
ZFraction operator/(ZFraction const& a, ZFraction const& b) {
	ZFraction result(a);
	return result /= b;
}

ZFraction operator+(ZFraction const& a, int const& b) {
	return a + ZFraction(b);
}
ZFraction operator-(ZFraction const& a, int const& b) {
	return a - ZFraction(b);
}
ZFraction operator*(ZFraction const& a, int const& b) {
	return a * ZFraction(b);
}
ZFraction operator/(ZFraction const& a, int const& b) {
	return a / ZFraction(b);
}

ZFraction operator+(int const& a, ZFraction const& b) {
	return ZFraction(a) + b;
}
ZFraction operator-(int const& a, ZFraction const& b) {
	return ZFraction(a) - b;
}
ZFraction operator*(int const& a, ZFraction const& b) {
	return ZFraction(a) * b;
}
ZFraction operator/(int const& a, ZFraction const& b) {
	return ZFraction(a) / b;
}

std::ostream& operator<<(std::ostream& stream, ZFraction fraction) {
	fraction.print(stream);
	return stream;
}