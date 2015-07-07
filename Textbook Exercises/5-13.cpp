#define fi "5-13.inp"
#define fo "5-13.out"
#define maxn 1000
#include <fstream>
using namespace std;

struct point {long x,y;} queue[maxn],start;

const long dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1};

long m,n,a[maxn][maxn],b[maxn][maxn],l,r;
bool avail[maxn][maxn];

void input() {
	ifstream f(fi);
	f >> m >> n;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			f >> a[i][j];
			if (a[i][j] == 2) {start.x=i; start.y=j;};
		}
	f.close();
	fill(avail,avail+maxn,true);
	l=1;
}

bool isEmpty() {
	return (l>r);
}

void enQueue(long x, long y) {
	queue[++r].x=x;
	queue[r].y=y;
}

point deQueue() {
	point res;
	res.x = queue[l].x;
	res.y = queue[l++].y;
	return res;
}

int main() {
	point u;
	enQueue(start.x,start.y);
	avail[start.x][start.y] = false;
	while (!isEmpty()) {
		u=deQueue();
		for (int i=0; i<4; i++) if (a[u.x+dx[i]][u.y+dy[i]] == 1) {
			b[u.x][u.y] ;
		}
	}
}
