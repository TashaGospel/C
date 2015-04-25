#include <iostream>
using namespace std;

void quicksort(int d, int c, int a[])
{
	int i = d, j = c, mid = a[(d+c)/2], tmp;
	do
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) 
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (d < j) quicksort(d,j,a);
	if (i < c) quicksort(i,c,a);
}

int main()
{
	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++) cin >> x[i];
	quicksort(0,n-1,x);
	for (int i = 0; i < n; i++) cout << x[i] << ' ';
}
