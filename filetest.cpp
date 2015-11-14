#include <iostream>
#include <iomanip>
using namespace std;

int a = 10, b = 20;

void thing(int* &p) {
    p = &b;
}

int main() {
    int *pa = &a;
    thing(pa);
    cout<< *pa;
}
