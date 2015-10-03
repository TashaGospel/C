#include <iostream>
using namespace std;

int main() {
    int n, prev, cur, res = 1, ans = 1;

    cin >> n >> cur;
    for (int i = 1; i < n; i++) {
        prev = cur;
        cin >> cur;
        if (cur >= prev) {
            res++;
            ans = (res > ans)? res : ans;
        }
        else res = 1;
    }
    
    cout << ans;
}
