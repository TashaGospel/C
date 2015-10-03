/* Tran Anh Tuan - September 3rd, 2015
 * Calculates 2^2003
 */

#include <iostream>
#include <string>
using namespace std;

string bigMul(string a, int b);
string bigPower(int base, int power);
string bigMod(string a, string b);

int main() {
    cout << bigPower(2,2003) << endl;

}

string bigMul(string a, int b) {
    int carry = 0, tmp;
    string res = "";
    for (int i = a.length(); i >= 1; i--) {
        tmp = (a[i-1] - '0') * b + carry;
        carry = tmp / 10;
        res = (char)(tmp % 10 + '0') + res;
    }
    if (carry > 0) res = to_string(carry) + res;
    return res;
}

string bigPower(int base, int power) {
    string res = "1";
    for (int i = 0; i < power; i++) res = bigMul(res,base);
    return res;
}
