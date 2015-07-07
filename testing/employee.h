#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employer;
class Position;

class Person {
	string m_Name;
	bool m_Employed = false;
	Position* m_Position;
	Employer* m_Employer;
public:
	 Person(string);
	 string toString();
	 void setPosition(Employer,Position);
};

class Employer {
	string m_Name,m_Market;
public:
	Employer(string,string);
	bool hire(Person&,Position);
	string toString();
};

class Position {
	string m_Name,m_Description;
public:
	Position(string,string);
	string toString();
};

#endif
