#include <iostream>
using namespace std;

#define maxval 100001

int n;
long long res;
int *p = new int[maxval];

void input();
long long max(long long, long long);
void process();
void output();

int main() {
	input();
	process();
	output();
}

void input() {
	int tmp;
	fill(p,p+maxval,0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		p[tmp]++;
	}
}

long long max(long long a, long long b) {
	return (a >= b) ? a : b;
}

void process() {
	long long *a = new long long[maxval];
	a[1] = p[1];
	for (int i = 2; i <= maxval; i++)
		a[i] = max(a[i-1], a[i-2] + (long long)i * p[i]);
	res = a[maxval];
	delete[] a;
}

void output() {
	cout << res;
	delete[] p;
}
