/*
문제 : Fly me to the Alpha Centauri(https://www.acmicpc.net/problem/1011)
 */

#include <iostream>

using namespace std;

long int func(long int x) {
	long int count = 0, n = 0;
	long int sum = 0;
	for (long int i = 1; sum < x; i++) {
		if (i % 2 == 0) {
			n = i / 2;
			sum = (n * n) + n;
			count = i;
		}
		else {
			n = (i - 1) / 2;
			sum = (n + 1) * (n + 1);
			count = i;
		}
	}
	return count;
}

int main() {
	int t;
	long int x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		cout << func(y - x) << endl;
	}
	return 0;
}
