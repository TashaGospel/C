#include <fstream>
using namespace std;

#define fi "1A.inp"
#define fo "1A.out"

void input(int &n, int &m, int &a);
long long process(int n, int m, int a);
void output(long long);

int main() {
	int n,m,a;
	input(n,m,a);
	output(process(n,m,a));
}

void input(int &n, int &m, int &a) {
	ifstream f(fi);
	f >> n >> m >> a;
	f.close();
}

long long process(int n, int m, int a) {
	int x = n / a;
	if (n % a != 0) x++;
	int y = m / a;
	if (m % a != 0) y++;
	return (long long)x * y;
}

void output(long long value) {
	ofstream f(fo);
	f << value;
	f.close();
}
