/*
¹®Á¦ : A+B -8(https://www.acmicpc.net/problem/11022)
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

	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}

	return 0;
}