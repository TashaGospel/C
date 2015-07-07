#define fi "16-2.inp"
#define fo "16-2.out"
#define maxn 1000
#include <fstream>
#include <string>
using namespace std;

long n,s,t,a[maxn][maxn],count,stack[maxn],trace[maxn];
bool avail[maxn];

void input() {
	ifstream f(fi);
	f >> n >> s >> t;
	for (int i=1; i <= n; i++)
		for (int j=1; j <= n; j++)
			f >> a[i][j];
	f.close();
	fill(avail,avail+maxn,true);
}

bool empty() {
	return (count==0);
}

void push(long c) {
	stack[++count]=c;
}

long pop() {
	return stack[count--];
}

void process() { //DFS
	int u;
	push(s);
	avail[s]=false;
	while (!empty()) {
		u=pop();
		for (int i=1; i<=n; i++) if (a[u][i] == 1 && avail[i]) {
			avail[i]=false;
			push(i);
			trace[i]=u;
		}

	}
}

string path(long c) {
	if (c==s) return string(1,char(c+48));
	else return path(trace[c]) + " " + char(c+48);
}

void output() {
	ofstream f(fo);
	if (avail[t]) f << "No";
	else {
		f << "Yes" << endl;
		f << path(t);
	}
	f.close();
}

int main() {
	input();
	process();
	output();
}
