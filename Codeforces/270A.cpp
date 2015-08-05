#include <fstream>
using namespace std;

#define fi "270A.inp"
#define fo "270A.out"

void parsefile();
bool isCorrect(int a);

int main() {
	parsefile();
}

void parsefile() {
	int n,a;
	ifstream f(fi);
	ofstream g(fo);
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> a;
		(isCorrect(a))? g << "YES\n" : g << "NO\n";
	}
	f.close();
	g.close();
}

bool isCorrect(int a) {
	return (360 % (180 - a) == 0);
}
