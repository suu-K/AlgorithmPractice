/*
문제 : 구구단(https://www.acmicpc.net/problem/2739)
*/

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++)
		cout << n << " * " << i << " = " << n * i << endl;
	return 0;
}