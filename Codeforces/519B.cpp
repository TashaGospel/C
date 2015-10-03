#include <iostream>
using namespace std;

int main() {
    int n, a[3] = {};

    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 0, tmp; j < n - i; j++) {
            cin >> tmp;
            a[i] += tmp;
        }

    cout << a[0] - a[1] << endl << a[1] - a[2];
}
