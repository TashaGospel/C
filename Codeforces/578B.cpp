#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 2;

int main() {
    int n, k, x, mul = 1;
    long long res = 0, a[maxn] = {}, l[maxn] = {}, r[maxn] = {};

    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        l[i] = l[i-1] | a[i];
        r[n - i + 1] = r[n - i + 2] | a[n - i + 1];
    }

    while (k--) mul *= x;

    for (int i = 1; i <= n; i++) res = max(res, (l[i-1] | (a[i] * mul) | r[i+1]));

    cout << res;
}
