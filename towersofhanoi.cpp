#include <iostream>
using namespace std;

void move(int n, int ori, int des)
{
	if (n==1) cout << ori << "->" << des << endl;
	else
	{
		move(n-1,ori,6-ori-des);
		cout << ori << "->" << des << endl;
		move(n-1,6-ori-des,des);
	}
}

int main()
{
	int n;
	cin >> n;
	move(n,1,3);
}