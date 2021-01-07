/*
문제 : 기찍n(https://www.acmicpc.net/problem/2742)
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int sum = 0;
	cin >> n;
	for (int i = n; i >= 1; i--)
		cout << i << "\n";
	return 0;
}