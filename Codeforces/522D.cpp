#include <iostream>
using namespace std;

#define maxn 500001
#define maxa 2000000001

int main() {
	int n, m, a[maxn], min, max;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> min >> max;
		for (int j = min; j <= max; j++) {

