#include "fraction.h"
using namespace std;

int gcd(int x, int y) {
	int a(x),b(y);
	while (a && b) {
		if (a>=b) a-=b;
		else b-=a;
	}
	if (a) return a; else return b;
}

void fraction::simplify() {
	int a = (m_numerator > 0)? m_numerator:-m_numerator, b = (m_denominator > 0)? m_denominator:-m_denominator;
	int factor = gcd(a,b);
	m_numerator/=factor;
	m_denominator/=factor;
}

fraction::fraction(int a, int b): m_numerator(a), m_denominator(b) {}

void fraction::set() {
	m_denominator=0;
	while (!m_denominator) {
		cin >> m_numerator >> m_denominator;
		if (m_numerator < 0 && m_denominator < 0) {
			m_numerator = -m_numerator;
			m_denominator = -m_denominator;
		}
		if (!m_denominator) cerr << "Denominator must not be 0!" << endl;
	}
}

double fraction::toDouble() {
	return 1.0 * m_numerator / m_denominator;
}

string fraction::toString() {
	return to_string(m_numerator) + '/' + to_string(m_denominator);
}

fraction fraction::add(fraction a) {
	fraction res;
	res.m_denominator = m_denominator*a.m_denominator;
	res.m_numerator = m_numerator*a.m_denominator + a.m_numerator*m_denominator;
	res.simplify();
	return res;
}

fraction fraction::subtract(fraction a) {
	fraction res;
	res.m_denominator = m_denominator*a.m_denominator;
	res.m_numerator = m_numerator*a.m_denominator - a.m_numerator*m_denominator;
	res.simplify();
	return res;
}

fraction fraction::multiply(fraction a) {
	fraction res;
	res.m_numerator = m_numerator * a.m_numerator;
	res.m_denominator = m_denominator * a.m_denominator;
	res.simplify();
	return res;
}

fraction fraction::divide(fraction a) {
	fraction res;
	res.m_numerator = m_numerator * a.m_denominator;
	res.m_denominator = m_denominator * a.m_numerator;
	res.simplify();
	return res;
}

ostream& operator<<(ostream& os, fraction a) {
	cout << a.m_numerator << '/' << a.m_denominator;
	return os;
}
