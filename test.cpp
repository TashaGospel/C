#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
class Student {
protected:
	string m_name;
	int m_year;
public:
	Student(string a = "Peter", int b = 3): m_name(a), m_year(b) {}
	string getName() { return m_name; }
	int getYear() { return m_year; } 
	virtual string getClassName() { return "Student"; }
};

class Undergrad: public Student {
	int m_birth;
public:
	Undergrad(string name, int year, int birth = 1990): Student(name, year), m_birth(birth) {} 
	int getBirth() { return m_birth; }

	string getClassName() { return "Undergrad"; }
	static void swap(int& a, int& b) { int tmp = a; a = b; b = tmp; }
};

class Grad: public Student {
	int m_gradYear;
public:
	Grad(int gradYear=2015): m_gradYear(gradYear) {}
	string getClassName() { return "Grad"; }
};

class No: public Undergrad {
	int m_number;
public:
	No(int number = 15): Undergrad("no", 3), m_number(number) {}
	string getClassName() { return "No"; }
};

string thing(Undergrad &a) {
	return a.getClassName();
}

int main()
{
	No a;
	cout << thing(a) << endl;
}
