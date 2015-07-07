#include <iostream>
using namespace std;

int main()
{
	int i[10][10], *p;
	i[9][9]=42;
	p = (int*)i;
	cout << i[0] << endl << p << endl << *(p+99) << endl << i << endl; 
}

