/*
문제 : 분해합(https://www.acmicpc.net/problem/2231)
 */

#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int sum = 0, tmp = 0;
	int m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum = tmp = i;
		while (tmp > 0) {
			sum += (tmp % 10);
			tmp /= 10;
		}
		if (sum == n) {
			m = i;
			break;
		}
	}
	cout << m << endl;
	return 0;
}