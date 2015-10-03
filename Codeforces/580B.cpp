#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 2;

struct thing {
    int m, s;
};

int n, d;
long long res;
thing a[maxn];

bool myComp(thing c, thing d) {
    return c.m <= d.m;
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i].m >> a[i].s;

    sort(a, a + n, myComp);

    for (int i = 0; i < n; i++) {
        long long cur = a[i].s;
        int j = i - 1;
        while (j >= 0 && a[i].m - a[j].m < d) {
            cur += a[j].s;
            j--;
        }
        res = (cur > res)? cur : res;
    }

    cout << res << endl;
}
