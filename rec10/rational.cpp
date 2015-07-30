#include "rational.h"
#include <iostream>



using namespace std;
namespace CS1124 {
		Rational::Rational(){}
		Rational::Rational(int numerator) : numerator(numerator), denominator(1){
			
		}
	   std::ostream& operator<< (std::ostream& cout, Rational& r){
			cout << r.numerator << "/" << r.denominator << endl;
			return cout;
		} 
		Rational& Rational::operator+= (Rational& r){
			numerator=((numerator*r.denominator) + (r.numerator * denominator));
			denominator=(denominator*r.denominator);
			return normalize();
		}
		bool Rational::operator== (Rational& r2){
			normalize();
			r2.normalize();
		return (numerator == r2.numerator && denominator == r2.denominator);
		}
		int Rational::getNumerator(){
			return numerator;
		}
		int Rational::getDenominator(){
			return denominator;
		}
		Rational& Rational::normalize(){
			int divisor = greatestCommonDivisor(numerator, denominator);
			numerator /= divisor;
			denominator /= divisor;

			return *this;
		}

		Rational Rational::operator++ (){
			numerator += denominator;
			return *this;
		}
		Rational Rational::operator++ (int dummy){
			Rational temp;
			temp.numerator = numerator;
			temp.denominator = denominator;
			++(*this);
			return temp;
		}
		void Rational::setDenominator(int newDenom){
			denominator = newDenom;
		}
		void Rational::setNumerator(int newNum){
			numerator = newNum;
		}
		istream& operator>> (istream& cin, Rational& r){
			int numerator;
			int denominator;
			char trash;
			cin >> numerator >> trash >> denominator;
			r.setDenominator(denominator);
			r.setNumerator(numerator);
			return cin;
		}
	int greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}
	Rational operator+(Rational r1, Rational& r2){
		r1 += r2;
		cout << r2;
		return r1;
	}
	bool operator== (int i, Rational& r1){
		Rational temp(i);
		return temp == r1;
	}
	bool operator!=(Rational& r1, Rational& r2){
		return !(r1 == r2);
	}
	Rational operator--(Rational& r){
		r.setNumerator(r.getNumerator() - r.getDenominator());
		return r;
	}
	Rational operator-- (Rational& r, int dummy){
		Rational temp;
		temp.setNumerator(r.getNumerator());
		temp.setDenominator(r.getDenominator());
		--r;
		return temp;
	}
} 