#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.length() > 10) {
            int num = s.length() - 2;
            cout << s[0] << num << s[s.length()-1] << endl;
        }
        else cout << s << endl;
    }
}
