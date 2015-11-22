#include <fstream>
#include <algorithm>
#define fi "road.inp"
#define fo "road.out"
#define maxn 202
using namespace std;

struct point {
    int x, y;
};

struct road {
    int u,v;
};

int n, m, res[maxn], resCount;
point p[maxn];
road r[maxn];
bool a[maxn][maxn], chosen[maxn];

float area(point p1, point p2, point p3) {
    return (p1.x * (p2.y - p3.y)
         + p2.x * (p3.y - p1.y)
         + p3.x * (p1.y - p2.y)) / 2.0;
}

bool intersect (point p1, point p2, point p3, point p4) {
    return ((area(p1,p2,p3) * area(p1,p2,p4) <= 0)
        &&  (area(p3,p4,p1) * area(p3,p4,p2) <= 0));
}

void connect(int p1, int p2, int p3, int p4) {
    if (intersect(p[p1],p[p2],p[p3],p[p4])) {
        a[p1][p3] = a[p1][p4] = true;
        a[p2][p3] = a[p2][p4] = true;
        a[p3][p1] = a[p3][p2] = true;
        a[p4][p1] = a[p4][p2] = true;
    }
}

void input() {
    ifstream f(fi);
    f >> n >> m;
    for (int i = 1; i <= n; i++) f >> p[i].x >> p[i].y;
    for (int i = 1; i <= m; i++) {
        f >> r[i].u >> r[i].v;
        a[r[i].u][r[i].v] = a[r[i].v][r[i].u] = true;
        for (int j = i-1; j >= 1; j--) connect(r[i].u, r[i].v, r[j].u, r[j].v);
    }
}

void visit(int c) {
    chosen[c] = true;
    res[++resCount] = c;
    for (int i = 1; i <= n; i++)
        if (a[c][i] && !chosen[i])
            visit(i);
}

void process(){
    visit(1);
    sort(res, res + resCount);
}

void output() {
    ofstream f(fo);
    f << resCount << endl;
    for (int i = 1; i <= resCount; i++)
        f << res[i] << ' ';
    f.close();
}

int main() {
    input();
    process();
    output();
}
