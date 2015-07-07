//Warshall Algorithm
#define fi "warshall.inp"
#define fo "warshall.out"
#define maxn 1000
#include <fstream>
using namespace std;

long n,m,b[maxn][maxn],count1=0;
bool a[maxn][maxn],avail[maxn];

void input() {
	long d1,d2;
	fill(a[0],a[0]+maxn*maxn,false);
	fill(avail,avail+maxn,true);
	ifstream f(fi);
	f >> n >> m;
	while (!f.eof()) {
		f >> d1 >> d2;
		a[d1][d2]=true;
	}
	f.close();
}

void warshall() {
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				a[i][j] = a[i][j] or (a[i][k] and a[k][j]);
}

void process() {
	int count2;
	for (int i=1; i<=n; i++) if (avail[i]) {
		count1++;
		count2=1;
		avail[i]=false;
		b[count1][count2]=i;
		for (int j=1; j<=n; j++) if (a[i][j] && avail[j]) {
			count2++;
			b[count1][count2]=j;
			avail[j]=false;
		}
	}
}

void output() {
	ofstream f(fo);
	for (int i=1; i<=count1; i++) {
		int j=1;
		while (b[i][j]) {
			f << b[i][j] << " ";
			j++;
		}
		f << endl;
	}
	f.close();
}

int main() {
	input();
	warshall();
	process();
	output();
}
