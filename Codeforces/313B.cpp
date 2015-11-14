#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; 
    int n, l, r;

    cin >> s >> n; 

    int a[s.length()] = {};

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) a[i] = a[i-1] + 1;
        else a[i] = a[i-1];
    }

    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        cout << a[r-1] - a[l-1] << endl;
    }
}
