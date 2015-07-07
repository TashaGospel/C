#include "employee.h"

Person::Person(string name):m_Name(name) {}

string Person::toString() {
	string res = m_Name;
	if (!m_Employed) res+=" is not employed.";
	else res+=" is employed by " + m_Employer->toString() + " at position " + m_Position->toString() + ".";
	return res;
}

void Person::setPosition(Employer name, Position position) {
	m_Employer = &name;
	m_Position = &position;
	m_Employed = true;
}

Employer::Employer(string name, string market) {
	m_Name = name;
	m_Market = market;
}

bool Employer::hire(Person& person,Position position) {
	person.setPosition(*this,position);
	return true;
}

string Employer::toString() {
	return m_Name+" in "+m_Market




