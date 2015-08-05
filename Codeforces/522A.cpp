#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define maxn 201

int n, a[maxn], nameNum, res;
string names[maxn];

void init() {
	nameNum = 0;
	names[0] = "polycarp";
	a[0] = 1;
}

int getPos(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i <= n; i++)
		if (str == names[i]) return i;
	names[++nameNum] = str;
	return nameNum;
}

void parseFile() {
	cin >> n;
	string tmp, reposter, poster;
	for (int i = 1; i <= n; i++) {
		cin >> reposter;
		cin >> tmp;
		cin >> poster;
		int x = getPos(reposter);
		int y = getPos(poster);
		a[x] = (a[x] > a[y] + 1) ? a[x] : a[y] + 1;
		res = (res < a[x]) ? a[x] : res;
	}
	cout << res;
}

int main() {
	init();
	parseFile();
}
