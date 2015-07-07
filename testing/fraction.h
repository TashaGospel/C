#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <iostream>
using namespace std;

class fraction {
public:
	int m_numerator,m_denominator;
	fraction(int=0,int=1);
	void set();
	void simplify();
	double toDouble();
	string toString();
	fraction add(fraction);
	fraction subtract(fraction);
	fraction multiply(fraction);
	fraction divide(fraction);
	friend ostream& operator<<(ostream&,fraction);
};

#endif
