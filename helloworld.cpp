#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	int a,sum,nghin,trame;
	cin >> a;
	sum = (nghin = a / 1000) + (trame=((a -= nghin*1000) / 100)) + ((a-=trame*100)/10) + (a % 10);
	cout << sum << ' ' << nghin << ' ' << trame;
}