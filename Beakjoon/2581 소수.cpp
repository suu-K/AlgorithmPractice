/*
문제 : 소수(https://www.acmicpc.net/problem/2581)
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b) {
	int sum = 0, m = b + 1;
	bool isPrime = true;
	for (int i = a; i <= b; i++) {
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime && i != 1) {
			sum += i;
			m = min(m, i);
		}
		isPrime = true;
	}
	if (m == b + 1) {
		cout << -1;
		return;
	}
	cout << sum << endl;
	cout << m << endl;
}

int main() {
	int n = 0, m = 0;
	cin >> m >> n;
	func(m, n);
	return 0;
}
