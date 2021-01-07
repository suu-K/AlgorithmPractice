/*
문제 더하기 사이클 (https://www.acmicpc.net/problem/1110)
*/

#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int a, b;
	int cycle = 0;
	cin >> n;
	int tmp = n;
	do {
		a = tmp / 10;
		b = tmp % 10;
		tmp = b * 10 + ((a + b) % 10);
		cycle += 1;

	} while (n != tmp);
	cout << cycle << endl;

	return 0;
}