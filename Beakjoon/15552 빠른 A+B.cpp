/*
문제 : 빠른 A+B(https://www.acmicpc.net/problem/15552)
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	int a = 0, b = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}