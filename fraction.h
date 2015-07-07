#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class fraction
{
	int numerator,denominator;
public:
	fraction(int = 0,int = 1);
	fraction(fraction&);
	fraction add(fraction);
	friend istream& operator>>(istream&,fraction&);
	friend ostream& operator<<(ostream&,fraction);
};

#endif
