#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main()
{
	char n;
	system("cls");
	cout << "Press Enter?";
	cin.ignore();
	system("cls & color 0a");
	srand(rand());
	for (int i = 0; i < 15000; ++i) cout << rand() % 10;
	system("cls & color 0c");
	cout << endl << "Program Terminated...";
	sleep(1);
	system("cls & color 07");
}