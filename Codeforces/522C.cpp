#include <iostream>
using namespace std;

#define maxn 100001

int testNum, n, k, a[maxn];

void parseFile() {
	int dish, disappointed;
	cin >> testNum;
	for (int i = 0; i < testNum; i++) {
		int wildCards = 0;
		bool reachedZero = false;
		cin >> n >> k;
		for (int j = 1; j <= k; j++) cin >> a[j];
		for (int j = 1; j < n; j++) {
			cin >> dish >> disappointed;

			if (disappointed && !(reachedZero)) {
				if (a[1] - wildCards <= 0) { reachedZero = true; goto fail; }
				int min = 1;
				for (int z = 2; z <= k; z++) 
					if (a[z] - wildCards <= 0) { reachedZero = true; goto fail; }
					else if (a[min] > a[z]) min = z;
				wildCards -= a[min];
				a[min] = 0;
			}
			fail:

			if (dish) a[dish]--;
			else wildCards++;
		}

		for (int j = 1; j <= k; j++) 
			if (a[j] - wildCards <= 0) cout << 'Y';
		   	else cout << 'N';
		cout << endl;
	}
}

int main() {
	parseFile();
}
