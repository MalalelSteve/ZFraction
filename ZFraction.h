#pragma once

#include <iostream>
#include <string>

class ZFraction {
public:
	ZFraction(int numerator, int denominator = 1);
	void print(std::ostream& stream);
	bool isEqual(ZFraction const& other) const;
	bool isLt(ZFraction const& other) const;
	void minimize(); //Minimise la fraction

	ZFraction& operator+=(ZFraction const& other);
	ZFraction& operator-=(ZFraction const& other);
	ZFraction& operator*=(ZFraction const& other);
	ZFraction& operator/=(ZFraction const& other);

	ZFraction& operator+=(int const& other);
	ZFraction& operator-=(int const& other);
	ZFraction& operator*=(int const& other);
	ZFraction& operator/=(int const& other);

private:
	int m_numerator;
	int m_denominator;
};

int pgcd(int a, int b); //Renvoie le pgcd de a et b

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);

ZFraction operator+(ZFraction const& a, int const& b);
ZFraction operator-(ZFraction const& a, int const& b);
ZFraction operator*(ZFraction const& a, int const& b);
ZFraction operator/(ZFraction const& a, int const& b);

ZFraction operator+(int const& a, ZFraction const& b);
ZFraction operator-(int const& a, ZFraction const& b);
ZFraction operator*(int const& a, ZFraction const& b);
ZFraction operator/(int const& a, ZFraction const& b);

std::ostream& operator<<(std::ostream& stream, ZFraction fraction);