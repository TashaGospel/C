#include <iostream>
#include "fraction.h"
#include "fraction.cpp"
using namespace std;

int main()
{
	fraction p1(1,3),p2,p3,*p4;
	cin >> p2;
	p3 = p1.add(p2);
	p4 = &p3;
	cout << p3;
	cout << &p4 << ' ' << *p4;
}
