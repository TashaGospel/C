#include <fstream>
#include <math.h>
#define fi "4-11.inp"
#define fo "4-11.out"
using namespace std;

int n,a[100],count=-1,cur=0;

void input()
{
	ifstream f(fi);
	f >> n;
	f.close();
}

int isprime(int num)
{
	if (num <=1) return 0;
	for (int i = 2; i <= sqrt(num); i++) if (num%i==0) return 0;
	return 1;
}

void process(int c)
{
	for (int i=0; i<=9; i++)
	{
		cur = cur*10+i;
		if (isprime(cur))
		{
			if (c == n) {count++;a[count]=cur;}
			else process(c+1);
		} 
		cur /= 10;
	}
}

void output()
{
	ofstream f(fo);
	f << count+1 << endl;
	for (int i=0; i <= count; i++) f << a[i] << endl;
	f.close();
}

int main()
{
	input();
	process(1);
	output();
}