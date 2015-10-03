#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int maxn = 1e5 + 10;

int main() {
    int chars[26];
    long long sum[maxn], res = 0;
    vector<int> pos[26];
    string s;

    for (int i = 0; i < 26; i++) cin >> chars[i];
    cin >> s;

    for (int i = 0; i < (int)s.length(); i++) {
        sum[i] = chars[s[i] - 'a'] + sum[i-1];
        pos[s[i] - 'a'].push_back(i);
    }

    for (int c = 0; c < 26; c++) {
        map<long long, int> m;
        for (int j = 0; j < (int)pos[c].size(); j++) {
            int p = pos[c][j];
            res += m[sum[p-1]];
            m[sum[p]]++;
        }
        m.clear();
    }

    cout << res;
}
