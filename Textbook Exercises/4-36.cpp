#include <fstream>
#define fi "4-36.inp"
#define fo "4-36.out"
#define maxn 101
using namespace std;

long n,a[maxn],res=0;

void input()
{
	ifstream f(fi);
	f >> n;
	for (int i=0; i < n; i++) f >> a[i];
	f.close();
}

void process()
{
	while (n > 1)
	{
		long minval=a[0]+a[1],minpos=0;
		for (int i=1; i < n-1; i++) if (a[i]+a[i+1] < minval) {minval = a[i]+a[i+1]; minpos=i;}
		a[minpos]=minval;
		res+=minval;
		n--;
		for (int i=minpos+1; i < n; i++) a[i]=a[i+1];
	}
}

void output()
{
	ofstream f(fo);
	f << res;
	f.close();
}

int main()
{
	input();
	process();
	output();
}