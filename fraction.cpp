#include "fraction.h"
#include <iostream>
using namespace std;

fraction::fraction(int a, int b): numerator(a),denominator(b) {}
fraction::fraction(fraction &p): numerator(p.numerator),denominator(p.denominator) {}

istream& operator>>(istream& is,fraction& p)
{
	is >> p.numerator >> p.denominator;
	return is;
}

ostream& operator<<(ostream& os,fraction p)
{
	os << p.numerator << "/" << p.denominator << endl;
	return os;
}

fraction fraction::add(fraction a)
{
	fraction res;
	res.numerator = numerator + a.numerator;
	res.denominator = denominator + a.denominator;
	return res;
}
