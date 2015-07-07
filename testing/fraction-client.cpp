#include "fraction.cpp"
using namespace std;

int main() {
	fraction p1,p2;
	p1.set();
	p2.set();
	string str = p1.toString();
	double dou = p2.toDouble();
	cout << str << endl << dou << endl;
	cout << (p1.add(p2)).add(p2) << endl << p1.subtract(p2) << endl; 
	cout << p1.multiply(p2) << endl << p1.divide(p2) << endl;
}
