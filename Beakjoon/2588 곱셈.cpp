/*
¹®Á¦ : °ö¼À(https://www.acmicpc.net/problem/2588)
*/

#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	cout << a * ((b % 100) % 10) << endl;
	cout << a * ((b % 100) / 10) << endl;
	cout << a * (b / 100) << endl;
	cout << a * b << endl;
	return 0;
}