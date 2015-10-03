#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 2;

int n, k, res;
vector<int> a[maxn];
int cats[maxn];

void visit(int c, int parent, int catNum) {
    if (catNum > k) return;
    if (a[c].size() == 1 && c != 1) res++;
    else for (size_t i = 0; i < a[c].size(); i++) if (a[c][i] != parent)
        visit(a[c][i], c, catNum * cats[a[c][i]] + cats[a[c][i]]);
}

int main () {
    int d1,d2;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> cats[i];
    for (int i = 1; i < n; i++) {
        cin >> d1 >> d2;
        a[d1].push_back(d2);
        a[d2].push_back(d1);
    }

    visit(1, -1, cats[1]);

    cout << res;
}
