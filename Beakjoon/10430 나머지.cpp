/*
문제 : 나머지(https://www.acmicpc.net/problem/10430)
*/

#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << (a + b)%c << endl;
	cout << ((a % c) + (b % c)) % c << endl;
	cout << (a*b) % c << endl;
	cout << ((a % c) * (b % c)) % c << endl;
	return 0;
}