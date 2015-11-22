#include <iostream>
#include <fstream>
#define fi "farmer.inp"
#define fo "farmer.out"
#define maxn 102
using namespace std;

int n, m, q, a[maxn], b[maxn], c[maxn][maxn], res;

void input() {
    ifstream f(fi);
    f >> q >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];
    f.close();
}

int max(int i, int j) {
    return (i >= j) ? i : j;
}

void process() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= q; j++) {
            c[i][j] = c[i-1][j];
            if (j - a[i] >= 0) c[i][j] = max(c[i][j], c[i-1][j-a[i]] + a[i]);
        }

    res = c[n][q];
    q -= res;
    for (int i = 1; i <= n; i++) fill(c[i], c[i] + q, 0);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= q; j++) {
            c[i][j] = c[i-1][j];
            if (j - b[i] >= 0) c[i][j] = max(c[i][j], c[i-1][j-b[i]] + b[i]);
        }

    if (c[m][q]) res += c[m][q] - 1;
}

void output() {
    ofstream f(fo);
    f << res;
    f.close();
}

int main() {
    input();
    process();
    output();
}
