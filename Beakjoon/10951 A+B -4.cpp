/*
문제 : A+B -4(https://www.acmicpc.net/problem/10951)
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a = 0, b = 0;
	while (cin >> a >> b) {
		cout << a + b << "\n";
	}
	return 0;
}