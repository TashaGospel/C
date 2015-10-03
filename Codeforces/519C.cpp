#include <iostream>
using namespace std;

int main() {
    int n, m, res = 0;
    cin >> n >> m;

    while (n && m && !(n == 1 && m == 1)) {
        if (n >= m) {
            n -= 2;
            m--;
            res++;
        }
        else {
            m -= 2;
            n--;
            res++;
        }
    }

    cout << res;
}
