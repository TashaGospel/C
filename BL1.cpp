#define fi "BL1.inp"
#define fo "BL2.out"
#define maxn 1000
#include <iostream>
#include <fstream>
using namespace std;

long n,k;

void input() {
	ifstream f(fi);
	f >> n >> k;
	long **a = new long*[n];
	for (int i = 0; i < n; i++) a[i] = new long[k];

}

int main() {
}
