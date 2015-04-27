#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
	ifstream fi("test.inp");
	char s[10];
	int a[4],n;
	for (int i=0; i<4; i++) {fi >> a[i];/*fi.ignore(numeric_limits<streamsize>::max(),'\n');*/}
	fi.close();
	ofstream fo("test.out");
	for (int i=0; i<4; i++) fo << a[i]+121 << ' ';
	fo.close();
}