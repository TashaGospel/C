#include <iostream>
using namespace std;

#define maxn 200001

unsigned int n, w[maxn], h[maxn], maxHeight = 0, secMaxHeight;
unsigned long long sumWidth = 0;

void input() {
	cin >> n;
	for (unsigned int i = 1; i <= n; i++) {
		cin >> w[i] >> h[i];
		sumWidth += w[i];
		if (maxHeight < h[i]) {
			secMaxHeight = maxHeight;
			maxHeight = h[i];
		}
		else if (secMaxHeight < h[i]) secMaxHeight = h[i];
	}
}

void process() {
	for (unsigned int i = 1; i <=n; i++) {
		unsigned int height;
		if (h[i] == maxHeight) height = secMaxHeight;
		else height = maxHeight;
		cout << (sumWidth - w[i]) * height << ' ';
	}
}

int main() {
	input();
	process();
}
