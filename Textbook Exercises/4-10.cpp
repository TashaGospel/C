#include <iostream>
#include <fstream>
#define fi "4-10.inp"
#define fo "4-10.out"
using namespace std;
int n, a[101][101],count=0;

void input()
{
	ifstream f(fi);
	f >> n;
	f.close();
	for (int i=1; i <= n; i++)
		for (int j=1; j <=n; j++) a[i][j]=0;
}

void output()
{
	ofstream f(fo);
	for (int i=1; i <= n; i++)
	{
		for (int j=1; j <=n; j++) f << a[i][j] << ' ';
		f << endl;
	}

}

void process(int x, int y)
{
	if ((x <= 0 || y <= 0) || (x > n || y > n) ||(a[x][y] != 0)) return;
	if (count == (n*n)-1) {a[x][y]=count+1; output(); a[x][y]=0;}
	else
	{
		count++;
		a[x][y]=count;
		process(x+2,y-1);
		process(x+2,y+1);
		process(x-2,y-1);
		process(x-2,y+1);
		process(x-1,y+2);
		process(x-1,y-2);
		process(x+1,y+2);
		process(x+1,y-2);
		a[x][y]=0;
		count--;
	}
}

int main()
{
	input();
	process(1,1);
}