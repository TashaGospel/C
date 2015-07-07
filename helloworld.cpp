#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <limits>
#include <climits>
using namespace std;
int main()
{
	system("cls");
	cout << "Press Enter?";
	cin.ignore(numeric_limits<long>::max(),'\n'); //numeric_limits<long>::max() is from <limits>
	system("cls & color 0a");
	srand(rand());
	for (int i = 0; i < 15000; ++i) cout << rand() % 10;
	system("cls & color 0c");
	cout << endl << "Program Terminated...";
	sleep(1); // from <unistd.h>
	system("cls & color 07");
	cout << LONG_MAX; //LONG_MAX is from <climits>
}
