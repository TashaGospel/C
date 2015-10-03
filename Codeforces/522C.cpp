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
				int min = (dish != 1) ? 1 : 2;
				if (a[min] <= 0) { reachedZero = true; goto fail; }
				for (int z = 1; z <= k; z++) 
					if (a[z] <= 0) { reachedZero = true; goto fail; }
					else if (a[min] > a[z] && z != dish) min = z;
				int minVal = a[min];
				for (int z = 1; z <= k; z++) if (z != dish && a[z] == minVal)
					a[z] = 0;
				wildCards -= a[min];
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
