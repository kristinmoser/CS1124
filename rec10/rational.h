#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace CS1124{
	class Rational{
	public:
		Rational();
		Rational(int numerator);
		Rational& operator+= (Rational& r);
		bool operator== (Rational& r2);
		friend std::ostream& operator<< (std::ostream& cout, Rational& r);
		Rational& normalize();
		Rational operator++ ();
		Rational operator++ (int dummy);
		void setDenominator(int newDenom);
		void setNumerator(int newNum);
		int getNumerator();
		int getDenominator();
	private:
		int numerator;
		int denominator;
	};
	std::istream& operator>> (std::istream& cin, Rational& r);
	int greatestCommonDivisor(int x, int y);
	bool operator== (int i, Rational& r1);
	Rational operator+(Rational r1, Rational& r2);
	bool operator!=(Rational& r1, Rational& r2);
	Rational operator--(Rational& r1);
	Rational operator-- (Rational& r1, int dummy);
}
#endif