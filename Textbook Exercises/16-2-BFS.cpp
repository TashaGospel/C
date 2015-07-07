#define fi "16-2.inp"
#define fo "16-2.out"
#define maxn 1000
#include <fstream>
#include <string>
using namespace std;

long n,s,t,a[maxn][maxn],l,r,queue[maxn],trace[maxn];
bool avail[maxn];

void input() {
	ifstream f(fi);
	f >> n >> s >> t;
	for (int i=1; i <= n; i++)
		for (int j=1; j <= n; j++)
			f >> a[i][j];
	f.close();
	fill(avail,avail+maxn,true);
	r=-1;
}

bool empty() {
	return (l > r);
}

void push(long c) {
	queue[++r]=c;
}

long pop() {
	return queue[l++];
}

void process() { //BFS
	int u;
	push(s);
	while (!empty()) {
		u=pop();
		if (avail[u]) {
			avail[u]=false;
			for (int i=1; i<=n; i++) if (avail[i] && a[u][i]==1) {
				trace[i]=u;
				push(i);
			}
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
