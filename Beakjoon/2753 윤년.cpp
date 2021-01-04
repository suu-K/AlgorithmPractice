/*
¹®Á¦ : À±³â(https://www.acmicpc.net/problem/2753)
*/

#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	cin >> year;

	if (year % 4 != 0)
		cout << 0 << endl;
	else if (year % 400 == 0)
		cout << 1 << endl;
	else if (year % 100 == 0)
		cout << 0 << endl;
	else
		cout << 1 << endl;
	return 0;
}