#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 1e8;

int s[maxn + 1]; // s[i] is the number of primes from 2 to i.
bool notPrime[maxn + 1];

void buildPrimes() {
    for (int i = 2; i <= floor(sqrt(maxn)); i++)
        for (int j = i; j <= (maxn / i); j++)
            notPrime[i*j] = true;

    for (int i = 2; i <= maxn; i++) {
        s[i] = s[i-1];
        if (!notPrime[i]) s[i]++;
    }
}

bool isTrue(int n) {
    float num = (s[n - 1] - s[(n - 1) / 2]) / float(s[n - 1]);
    return ((1.0/3) <= num && num <= (1.0/2));
}

int main() {
    buildPrimes();
    int numTrue = 0, numFalse = 0;
    for (int i = 5; i <= maxn; i++) if (isTrue(i)) numTrue++; else numFalse++;
    cout << "True for: " << numTrue << '.' << endl;
    cout << "False for: " << numFalse << '.' << endl;

    for (int i = 5; i <= 101; i++)
        cout << i << ' ' << (s[i - 1] - s[(i - 1) / 2]) / float(s[i - 1]) << ' ' << isTrue(i) << endl;
}

